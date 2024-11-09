#include "ppp2/std_lib_facilities.h"

class Date
{
    int y, m, d;

public:
    Date(int y, int m, int d);
    void add_day(int n);

    int year() const
    {
        return y;
    }

    int month() const
    {
        return m;
    }

    int day() const
    {
        return d;
    }
};

Date::Date(int yy, int mm, int dd)

{
    if(yy < 1)
    {
        error("invalid year");
    }
    if(mm < 1 || mm > 12)
    {
        error("invalid month");
    }
    if(dd < 1 || dd > 31)
    {
        error("invalid day");
    }
    y = yy;
    m = mm;
    d = dd;
}

void Date::add_day(int n)
{
    d += n;
    while(d > 31)
    {
        ++m;
        if(m > 12)
        {
            ++y;
            m = 1;
        }
        d -= 31;
    }
    while(d < 1)
    {
        --m;
        if(m < 1)
        {
            --y;
            if(y < 1)
            {
                error("add day: invalid year");
            }

            m = 12;
        }
        d += 31;
    }
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

void f()
{
    Date today{1978, 6, 25};
    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';

    Date invalid{2004, 13, -5};
    cout << "invalid: " << invalid << '\n';
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