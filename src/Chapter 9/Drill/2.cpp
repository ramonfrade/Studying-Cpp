#include "ppp2/std_lib_facilities.h"

// simple Date
// guarantee initialization with constructor
// provide some notational convenience
struct Date
{
    int y, m, d;               // year, month, day
    Date(int y, int m, int d); // check for valid date and initialize
    void add_day(int n);       // increase the Date by n days
};

Date ::Date(int yy, int mm, int dd)
{
    if(mm < 1 || mm > 12)
        error("invalid month");
    if(dd < 1 || dd > 31)
        error("invalid day");
    if(yy < 1)
        error("invalid year");
    y = yy;
    m = mm;
    d = dd;
}

void Date ::add_day(int n)
{
    if(d > 31)
    {
        ++m;
        d -= 31;
    }
    if(d < 1)
    {
        --m;
        d += 31;
    }
    if(m > 12)
    {
        ++y;
        m -= 12;
    }
    if(m < 1)
    {
        --y;
        m += 12;
    }
    if(y < 1)
        error("add day: invalid year");

    d += n;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

void f()
{
    Date today(1978, 6, 25);
    cout << today << '\n'; // use today
    Date tomorrow(today);
    tomorrow.add_day(1);
    cout << tomorrow << '\n'; // use tomorrow
}
int main()
try
{
    f();
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
