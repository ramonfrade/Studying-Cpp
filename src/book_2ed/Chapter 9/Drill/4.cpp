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

class Year
{
    static const int min = 1800;
    static const int max = 2200;

public:
    class Invalid
    {
    };

    Year(int x) : y{x}
    {
        if(x < min || max <= x)
            throw Invalid{};
    }

    int year() const
    {
        return y;
    }

private:
    int y;
};

Year operator+(const Year& y, int n)
{
    int r = y.year() + n;
    return Year(r);
}

Year operator-(const Year& y, int n)
{
    int r = y.year() - n;
    if(r < 1)
    {
        error("Year operator-: year cannot be zero or negative");
    }

    return Year(r);
}

Year& operator++(Year& y)
{
    y = y + 1;
    return y;
}

Year& operator--(Year& y)
{
    y = y - 1;
    return y;
}

class Date
{
    Year y;
    Month m;
    int d;

public:
    Date(Year y, Month m, int d);
    void add_day(int n);

    int year() const
    {
        return y.year();
    }

    int month() const
    {
        return int(m);
    }

    int day() const
    {
        return d;
    }
};

Date::Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd}
{

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

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

void f()
{
    Date today{Year(1978), Month::jun, 25};
    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';
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