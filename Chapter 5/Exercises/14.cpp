#include "../../../std_lib_facilities.h"

// declaring vectors and rejected values
vector<int> monday = {};
vector<int> tuesday = {};
vector<int> wednesday = {};
vector<int> thursday = {};
vector<int> friday = {};
vector<int> saturday = {};
vector<int> sunday = {};
int rejected = 0;

// check and store the value in the right vector day
void check_day(string day, int val)
{
    if (day == "monday" || day == "Monday" || day == "mon" || day == "Mon")
    {
        monday.push_back(val);
    }
    else if (day == "tuesday" || day == "Tuesday" || day == "tue" || day == "Tue")
    {
        tuesday.push_back(val);
    }
    else if (day == "wednesday" || day == "Wednesday" || day == "wed" || day == "Wed")
    {
        wednesday.push_back(val);
    }
    else if (day == "thursday" || day == "Thursday" || day == "thu" || day == "Thu")
    {
        thursday.push_back(val);
    }
    else if (day == "friday" || day == "Friday" || day == "fri" || day == "Fri")
    {
        friday.push_back(val);
    }
    else if (day == "saturday" || day == "Saturday" || day == "sat" || day == "Sat")
    {
        saturday.push_back(val);
    }
    else if (day == "sunday" || day == "Sunday" || day == "sun" || day == "Sun")
    {
        sunday.push_back(val);
    }
    else
        rejected++;
}

// cout the values of the seven day-of-the-week vectors
void cout_values(vector<int> day)
{
    if (day.size() == 0)
    {
        cout << " doesn't have values. \n";
    }

    for (int i = 0; i < day.size(); i++)
    {
        if (day.size() == 1)
        {
            cout << " values are: " << day[i] << ".\n";
        }
        else if (i == 0)
        {
            cout << " values are: " << day[i] << ", ";
        }
        else if (i == day.size() - 1)
        {
            cout << day[i] << ".\n";
        }
        else
        {
            cout << day[i] << ", ";
        }
    }
}

// cout sum of the values in the vectors
void sum_vector_values(vector<int> day)
{
    int sum = 0;
    if (day.size() == 0)
    {
        return;
    }
    else
        for (int i = 0; i < day.size(); i++)
        {
            sum += day[i];
        }
    cout << "The sum of the values is: " << sum << '\n';
}

int main()
try
{
    string day;
    int val;
    cout << "Enter a day-of-the-week, value: (type '|' twice to exit) \n";
    while (cin >> day >> val)
    {
        if (day == "|")
        {
            break;
        }
        check_day(day, val);
    }
    cout << "Monday";
    cout_values(monday);
    sum_vector_values(monday);

    cout << "Tuesday";
    cout_values(tuesday);
    sum_vector_values(tuesday);

    cout << "Thursday";
    cout_values(thursday);
    sum_vector_values(thursday);

    cout << "Friday";
    cout_values(friday);
    sum_vector_values(friday);

    cout << "Saturday";
    cout_values(saturday);
    sum_vector_values(saturday);

    cout << "Sunday";
    cout_values(sunday);
    sum_vector_values(sunday);

    cout << "The number of rejected values is: " << rejected << '\n';
}

catch (exception &e)
{
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...)
{
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
