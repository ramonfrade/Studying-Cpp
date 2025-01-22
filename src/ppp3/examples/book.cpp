#include "ppp3/graphics/Graph.h"
#include "ppp3/graphics/Window.h"

using namespace Graph_lib;

int main(int argc, char* argv[])
{
    Application app;
    Window window({20, 20}, 600, 400, "Main window");
    Text text({150, 20}, "They are heeere!");
    window.attach(text);
    app.gui_main();
    return 0;
}
