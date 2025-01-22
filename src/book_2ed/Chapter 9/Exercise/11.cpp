//I made the functions here before copying them to Chrono.h

#include "Chrono.h"
#include "ppp2/std_lib_facilities.h"

using Chrono::Date;
using Chrono::Day;
using Chrono::Month;

const Date first_date{1970, Month::jan, 1}; //first day we are using here
const Day first_day = Day::thursday;        //first day was a thursday

// number of leap years between 1970 and Jan 1, year y
int n_leapyears(int y)
{
    // go through every year since 1970, check if it is a leap year
    int nl = 0;
    for(int i = 1970; i < y; ++i)
    {
        if(Chrono::leapyear(i))
            ++nl;
    }
    return nl;
}

// number of days in the year before Month m, ignoring leap years
int nmonth2(Month m)
{
    switch(m)
    {
        case Month::jan: return 0;
        case Month::feb: return 31;
        case Month::mar: return 31 + 28;
        case Month::apr: return 31 + 28 + 31;
        case Month::may: return 31 + 28 + 31 + 30;
        case Month::jun: return 31 + 28 + 31 + 30 + 31;
        case Month::jul: return 31 + 28 + 31 + 30 + 31 + 30;
        case Month::aug: return 31 + 28 + 31 + 30 + 31 + 30 + 31;
        case Month::sep: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
        case Month::oct: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        case Month::nov: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        case Month::dec: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
    }
}

// number of day in year
int day_in_year(const Date& d)
{
    int diy = nmonth2(d.month()); // days in months before d
    diy += d.day();               // days in month of d
    if(Chrono::leapyear(d.year()) && d.month() > Month::feb)
        ++diy; // add day if leap year and later than February
    return diy;
}

// number of days since Jan 1, 1970 (day 0)
long int days_linear(const Date& d)
{
    if(d.year() < first_date.year())
        error("days_linear: year must be 1970 or later");
    int y = d.year() - first_date.year();
    return y * 365 + n_leapyears(d.year()) + day_in_year(d) - 1;
}

Day day_of_week(const Date& d)
{
    if(d.year() < first_date.year())
        error("day_of_week: works only for 1970 and later");
    int dlin = days_linear(d);
    return Day((int(first_day) + dlin) % 7);
}

bool is_workday(const Day& d)
{
    switch(int(d))
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5: return true; break;
        default: return false; break;
    }
}

Date next_workday(const Date& d)
{
    Date next_day = d;
    next_day.add_day(1);
    day_of_week(next_day);
    while(!is_workday(day_of_week(next_day))) { next_day.add_day(1); }
    return next_day;
}

int week_of_year(const Date& d)
{
    Date first_week{d.year(), Month::jan, 1};
    long int x = days_linear(d) - days_linear(first_week);
    return 1 + (x / 7);
}
