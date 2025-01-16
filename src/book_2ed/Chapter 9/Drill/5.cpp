#include "ppp2/std_lib_facilities.h"

enum class Month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

Month operator+(const Month& m, int n)
{
    int r = (int(m) + n);
    return Month(r);
}

Month operator-(const Month& m, int n)
{
    return (m + (-n));
}

Month& operator++(Month& m)
{
    m = m + 1;
    return m;
}

Month& operator--(Month& m)
{
    m = m - 1;
    return m;
}

class Date
{
public:
    Date(int y, Month m, int d);

    int year() const
    {
        return y;
    }

    Month month() const
    {
        return m;
    }

    int day() const
    {
        return d;
    }

    void add_day(int n);
    void add_month(int n);
    void add_year(int n);

private:
    int y;
    Month m;
    int d;
};

Date::Date(int yy, Month mm, int dd) : y{yy}, m{mm}, d{dd}
{
    if(y < 1)
    {
        error("invalid year");
    }
    if(m < Month::jan || m > Month::dec)
    {
        error("invalid month");
    }
    if(d < 1 || d > 31)
    {
        error("invalid day");
    }
}

void Date::add_day(int n)
{
    d += n;
    while(d > 31)
    {
        ++m;
        if(m > Month::dec)
        {
            ++y;
            m = Month::jan;
        }
        d -= 31;
    }
    while(d < 1)
    {
        --m;
        if(m < Month::jan)
        {
            --y;
            m = Month::dec;
        }
        d += 31;
    }
}

void Date::add_month(int n)
{
    int r = int(m) - 1 + n;
    y += r / 12;
    r %= 12;
    if(r < 0)
    {
        r += 12;
        y -= 1;
    }
    m = Month(r + 1);
}

void Date::add_year(int n)
{
    y += n;
    if(y < 1)
    {
        error("add year: invalid year");
    }
}

ostream& operator<<(ostream& os, const Date& d)
{
    static const char* month_names[]
        = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
    return os << '(' << d.year() << ',' << month_names[int(d.month()) - 1] << ',' << d.day() << ')';
}

void f()
{
    Date today{1978, Month::jun, 25};
    Date tomorrow = today;
    tomorrow.add_day(1);
    Date test = today;
    test.add_month(7);
    test.add_year(7);

    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';
    cout << "Test: " << test << '\n';
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