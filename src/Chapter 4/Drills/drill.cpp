#include "ppp2/std_lib_facilities.h"

int main()
{
    double val = 0;
    double small = 0;
    double large = 0;
    double sum = 0;
    double original_small = 0;
    double original_large = 0;
    string unit;
    string small_unit;
    string large_unit;
    vector<double> v = {};
    while(cin >> val >> unit)
    {
        double modval = val;
        if(unit == "cm")
        {
            double modval;
            modval = modval / 100.0;
        }
        else if(unit == "in")
        {
            modval = modval * 2.54 / 100;
        }
        else if(unit == "ft")
        {
            modval = modval * 12.0 * 2.54 / 100;
        }
        else if(unit == "m")
        {
            modval = modval;
        }
        else
        {
            cout << "not a valid unit\n";
            break;
        }
        v.push_back(modval);
        if(small == 0 || modval <= small)
        {
            small = modval;
            original_small = val;
            small_unit = unit;
            cout << val << unit << " the smallest so far\n";
        }
        else if(modval >= large)
        {
            large = modval;
            original_large = val;
            large_unit = unit;
            cout << val << unit << " the largest so far\n";
        }
        else
            cout << val << '\n';
        sum += modval;
    }
    sort(v);
    cout << "The smallest is: " << original_small << small_unit << '\n';
    cout << "The largest is: " << original_large << large_unit << '\n';
    cout << "The number of values is: " << v.size() << '\n';
    cout << "The sum of values is: " << sum << "m\n";
    for(int i = 0; i < v.size(); ++i) cout << v[i] << "m, ";
}
