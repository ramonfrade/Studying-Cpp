#include "ppp2/std_lib_facilities.h"

// simple Date (too simple?)
struct Date
{
    int y; // year
    int m; // month in year
    int d; // day of month
};

Date today; // a Date variable (a named object)
Date tomorrow;

// helper functions:

void init_day(Date& dd, int y, int m, int d)
{
    // check that (y,m,d) is a valid date
    // if it is, use it to initialize dd
    if(m < 1 || m > 12)
        error("invalid month");
    if(d < 1 || d > 31)
        error("invalid day");
    if(y < 1)
        error("invalid year");

    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n)
{
    // increase dd by n days
    dd.d += n;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

void f()
{
    init_day(today, 1978, 6, 25);
    tomorrow = today;
    add_day(tomorrow, 1);
}

int main()
{
    try
    {
        f();
        cout << "Today: " << today << '\n';
        cout << "Tomorrow: " << tomorrow << '\n';
    }
    catch(exception& e)
    {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch(...)
    {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
}
