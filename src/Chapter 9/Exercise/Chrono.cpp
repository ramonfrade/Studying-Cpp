// Chrono.cpp

//Borrowed from §9.8 with additions from 9.drill.05.cpp

#include "Chrono.h"

namespace Chrono
{
    //Month operators functions:
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

    // member function definitions:

    Date::Date(int yy, Month mm, int dd) : y{yy}, m{mm}, d{dd}
    {
        if(!is_date(yy, mm, dd))
            throw Invalid{};
    }

    const Date& default_date()
    {
        static Date dd{2001, Month::jan, 1}; // start of 21st century
        return dd;
    }

    Date::Date() : y{default_date().year()}, m{default_date().month()}, d{default_date().day()} {}

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
        if(m == Month::feb && d == 29 && !leapyear(y + n))
        {                   // beware of leap years!
            m = Month::mar; // use March 1 instead of February 29
            d = 1;
        }
        y += n;
    }

    // helper functions:

    bool is_date(int y, Month m, int d)
    {
        // assume that y is valid

        if(d <= 0)
            return false; // d must be positive
        if(m < Month::jan || Month::dec < m)
            return false;

        int days_in_month = 31; // most months have 31 days

        switch(m)
        {
            case Month::feb: // the length of February varies
                days_in_month = (leapyear(y)) ? 29 : 28;
                break;
            case Month::apr:
            case Month::jun:
            case Month::sep:
            case Month::nov:
                days_in_month = 30; // the rest have 30 days
                break;
        }

        if(days_in_month < d)
            return false;

        return true;
    }

    bool leapyear(int y)
    {
        // see exercise 10
        return false;
    }

    bool operator==(const Date& a, const Date& b)
    {
        return a.year() == b.year() && a.month() == b.month() && a.day() == b.day();
    }

    bool operator!=(const Date& a, const Date& b)
    {
        return !(a == b);
    }

    ostream& operator<<(ostream& os, const Date& d)
    {
        static const char* month_names[]
            = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
        return os << '(' << d.year() << ',' << month_names[int(d.month()) - 1] << ',' << d.day() << ')';
    }

    istream& operator>>(istream& is, Date& dd)
    {
        int y, m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if(!is)
            return is;
        if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
        {                                // oops: format error
            is.clear(ios_base::failbit); // set the fail bit
            return is;
        }

        dd = Date(y, Month(m), d); // update dd

        return is;
    }
} // namespace Chrono