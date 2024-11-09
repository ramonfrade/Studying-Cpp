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

void init_day(Date& dd, int y, int m, int d) //initialize and check if date is valid
{
    if(y < 1)
    {
        error("invalid year");
    }
    if(m < 1 || m > 12)
    {
        error("invalid month");
    }
    if(d < 1 || d > 31)
    {
        error("invalid day");
    }

    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n) // increase day by n
{
    dd.d += n;
    while(dd.d > 31)
    {
        ++dd.m;
        if(dd.m > 12)
        {
            ++dd.y;
            dd.m = 1;
        }
        dd.d -= 31;
    }
    while(dd.d < 1)
    {
        --dd.m;
        if(dd.m < 1)
        {
            --dd.y;
            if(dd.y < 1)
            {
                error("add day: invalid year");
            }

            dd.m = 12;
        }
        dd.d += 31;
    }
}

void f()
{
    init_day(today, 1978, 6, 25);
    tomorrow = today;
    add_day(tomorrow, 1);
}

ostream& operator<<(ostream& os, const Date& dd)
{
    return os << '(' << dd.y << ',' << dd.m << ',' << dd.d << ')';
}

int main()
{
    try
    {
        f();
        cout << "Today: " << today << '\n';
        cout << "Tomorrow: " << tomorrow << '\n';

        Date invalid;
        init_day(invalid, 2004, 13, -5);

        cout << "invalid: " << invalid << '\n';
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
