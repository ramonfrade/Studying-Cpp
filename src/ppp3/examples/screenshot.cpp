#include <QApplication>
#include <QCheckBox>
#include <QDir>
#include <QFileDialog>
#include <QGroupBox>
#include <QGuiApplication>
#include <QImageWriter>
#include <QLabel>
#include <QList>
#include <QMessageBox>
#include <QPushButton>
#include <QResizeEvent>
#include <QScreen>
#include <QSpinBox>
#include <QStandardPaths>
#include <QString>
#include <QSysInfo>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include <QWindow>

class Screenshot : public QWidget
{
    Q_OBJECT

public:
    Screenshot();

protected:
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void newScreenshot();
    void saveScreenshot();
    void shootScreen();
    void updateCheckBox();

private:
    void updateScreenshotLabel();

    QPixmap originalPixmap;

    QLabel* screenshotLabel;
    QSpinBox* delaySpinBox;
    QCheckBox* hideThisWindowCheckBox;
    QPushButton* newScreenshotButton;
};

Screenshot::Screenshot() : screenshotLabel(new QLabel(this))
{
    screenshotLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    screenshotLabel->setAlignment(Qt::AlignCenter);

    const QRect screenGeometry = screen()->geometry();
    screenshotLabel->setMinimumSize(screenGeometry.width() / 8, screenGeometry.height() / 8);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(screenshotLabel);

    QGroupBox* optionsGroupBox = new QGroupBox(tr("Options"), this);
    delaySpinBox = new QSpinBox(optionsGroupBox);
    delaySpinBox->setSuffix(tr(" s"));
    delaySpinBox->setMaximum(60);

    connect(delaySpinBox, &QSpinBox::valueChanged, this, &Screenshot::updateCheckBox);

    hideThisWindowCheckBox = new QCheckBox(tr("Hide This Window"), optionsGroupBox);

    QGridLayout* optionsGroupBoxLayout = new QGridLayout(optionsGroupBox);
    optionsGroupBoxLayout->addWidget(new QLabel(tr("Screenshot Delay:"), this), 0, 0);
    optionsGroupBoxLayout->addWidget(delaySpinBox, 0, 1);
    optionsGroupBoxLayout->addWidget(hideThisWindowCheckBox, 1, 0, 1, 2);

    mainLayout->addWidget(optionsGroupBox);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    newScreenshotButton = new QPushButton(tr("New Screenshot"), this);
    connect(newScreenshotButton, &QPushButton::clicked, this, &Screenshot::newScreenshot);
    buttonsLayout->addWidget(newScreenshotButton);
    QPushButton* saveScreenshotButton = new QPushButton(tr("Save Screenshot"), this);
    connect(saveScreenshotButton, &QPushButton::clicked, this, &Screenshot::saveScreenshot);
    buttonsLayout->addWidget(saveScreenshotButton);
    QPushButton* quitScreenshotButton = new QPushButton(tr("Quit"), this);
    quitScreenshotButton->setShortcut(Qt::CTRL | Qt::Key_Q);
    connect(quitScreenshotButton, &QPushButton::clicked, this, &QWidget::close);
    buttonsLayout->addWidget(quitScreenshotButton);
    buttonsLayout->addStretch();
    mainLayout->addLayout(buttonsLayout);

    shootScreen();
    delaySpinBox->setValue(5);

    setWindowTitle(tr("Screenshot"));
    resize(300, 200);
}

void Screenshot::resizeEvent(QResizeEvent* /* event */)
{
    QSize scaledSize = originalPixmap.size();
    scaledSize.scale(screenshotLabel->size(), Qt::KeepAspectRatio);
    if(scaledSize != screenshotLabel->pixmap().size())
        updateScreenshotLabel();
}

void Screenshot::newScreenshot()
{
    if(hideThisWindowCheckBox->isChecked())
        hide();
    newScreenshotButton->setDisabled(true);

    QTimer::singleShot(delaySpinBox->value() * 1000, this, &Screenshot::shootScreen);
}

void Screenshot::saveScreenshot()
{
    const QString format = "png";
    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    if(initialPath.isEmpty())
        initialPath = QDir::currentPath();
    initialPath += tr("/untitled.") + format;

    QFileDialog fileDialog(this, tr("Save As"), initialPath);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setDirectory(initialPath);
    QStringList mimeTypes;
    const QList<QByteArray> baMimeTypes = QImageWriter::supportedMimeTypes();
    for(const QByteArray& bf : baMimeTypes) mimeTypes.append(QLatin1String(bf));
    fileDialog.setMimeTypeFilters(mimeTypes);
    fileDialog.selectMimeTypeFilter("image/" + format);
    fileDialog.setDefaultSuffix(format);
    if(fileDialog.exec() != QDialog::Accepted)
        return;
    const QString fileName = fileDialog.selectedFiles().first();
    if(!originalPixmap.save(fileName))
    {
        QMessageBox::warning(this,
                             tr("Save Error"),
                             tr("The image could not be saved to \"%1\".").arg(QDir::toNativeSeparators(fileName)));
    }
}

void Screenshot::shootScreen()
{
    QScreen* screen = QGuiApplication::primaryScreen();
    if(const QWindow* window = windowHandle())
        screen = window->screen();
    if(!screen)
        return;

    if(delaySpinBox->value() != 0)
        QApplication::beep();

    originalPixmap = screen->grabWindow(0);
    updateScreenshotLabel();

    newScreenshotButton->setDisabled(false);
    if(hideThisWindowCheckBox->isChecked())
        show();
}

void Screenshot::updateCheckBox()
{
    if(delaySpinBox->value() == 0)
    {
        hideThisWindowCheckBox->setDisabled(true);
        hideThisWindowCheckBox->setChecked(false);
    }
    else
    {
        hideThisWindowCheckBox->setDisabled(false);
    }
}

void Screenshot::updateScreenshotLabel()
{
    screenshotLabel->setPixmap(
        originalPixmap.scaled(screenshotLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Screenshot scr;
    scr.resize(600, 500);
    scr.show();
    return app.exec();
}
