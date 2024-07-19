#include "ppp2/std_lib_facilities.h"

int main()
{
    vector<double> temps{};
    double median = 0;
    double first_num = 0;
    double second_num = 20;
    for(double temp; cin >> temp;)
    {
        temps.push_back(temp);
        sort(temps);
        if(temps.size() % 2 == 0)
        {
            first_num = temps[temps.size() / 2];
            second_num = temps[temps.size() / 2 - 1];
            median = first_num + second_num;
            cout << "The median of temperatures is: " << median / 2 << '\n';
        }
        else
            cout << "The median of temperatures is: " << temps[temps.size() / 2] << '\n';
    }
}
