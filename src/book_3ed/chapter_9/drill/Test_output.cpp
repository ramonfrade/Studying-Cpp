#include "ppp3/ppp.h"

/* Drill 1-7
    int birth_year = 2005;
    int age = 19;
    cout << "Decimal: " << birth_year << "\tHexadecimal: " << hex << birth_year << "\tOctal: " << oct << birth_year
         << '\n';
    cout << "My age: " << dec << age << '\n';
    int a, b, c, d = 0;
    */

/* Drill 8
    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n'; 
    */

/* Drill 9
    constexpr double number = 1234567.89;
    cout << "Default float: " << defaultfloat << number << "\tFixed: " << fixed << number
         << "\tScientific: " << scientific << number << '\n';
    */

/* Drill 10
    vector<string> first_names{"Ramon", "Luiz", "Pedro", "Wallace", "Nicolas", "Enzo"};
    vector<string> last_names{"Frade", "Mauricio", "Pessanha", "Correa", "Chacar", "Rangel"};
    vector<string> telephone{"22999535725", "22999341941", "22999571723", "22999123456", "22999654321", "22999123581"};
    vector<string> email{"ramonfrade7@gmail.com",
                         "luizmauricio@gmail.com",
                         "pedropessanha@gmail.com",
                         "wallacecorrea@gmail.com",
                         "nicolaschacar@gmail.com",
                         "enzorangel@gmail.com"};

    cout << left << setw(15) << "First Name:" << left << setw(14) << "Last Name:" << left << setw(21)
         << "Telephone number:" << left << "Email:\n";
    for(int i = 0; i < 6; i++)
    {
        cout << left << setw(15) << first_names[i] << left << setw(14) << last_names[i] << left << setw(21)
             << telephone[i] << left << email[i] << '\n';
    }
    */

struct Point
{
    int x, y = 0;
};

bool operator==(const Point& a, const Point& b)
{
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Point& a, const Point& b)
{
    return !(a == b);
}

ostream& operator<<(ostream& os, const Point& p)
{
    return os << '(' << p.x << ',' << p.y << ')';
}

istream& operator>>(istream& is, Point& p)
{
    int x, y;
    char ch1, ch2, ch3;
    is >> ch1 >> x >> ch2 >> y >> ch3;
    if(!is)
        return is;
    if(ch1 != '(' || ch2 != ',' || ch3 != ')')
    {
        is.clear(ios::failbit);
        return is;
    }
    p.x = x;
    p.y = y;
    return is;
}

int main()
{

    vector<Point> original_points;
    cout << "Enter coordinates in (x,y) format, one per line. Press Ctrl+Z to stop: \n";
    for(Point p; cin >> p;) { original_points.push_back(p); }

    string filename;
    cout << "Please enter the name of output file: \n";
    cin.clear();
    cin >> filename;
    ofstream ofs{filename};
    if(!ofs)
        error("cant open output file");

    for(const Point& p : original_points) { ofs << p << '\n'; }
    ofs.close();

    ifstream ifs{filename};
    if(!ifs)
        error("cant open input file");

    vector<Point> processed_points;
    for(Point p; ifs >> p;) { processed_points.push_back(p); }

    cout << "\nThese are the coordinates listed in original points vector: \n";
    for(const Point& p : original_points) { cout << p << '\n'; }

    cout << "\nThese are the coordinates listed in processed points vector: \n";
    for(const Point& p : processed_points) { cout << p << '\n'; }

    if(original_points != processed_points)
    {
        cout << "Something's wrong!\n";
    }
    else
        cout << "Success! The vectors are identical.\n";
}