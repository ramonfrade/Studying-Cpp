#include "ppp2/std_lib_facilities.h"

vector<double> values{};
vector<double> diffs{};

double sum_vec(int n)
{
    // function to sum 'n' values
    double z = 0;
    for(int i = 0; i < n; i++) { z += values[i]; }

    return z;
}

int main()
try
{
    // get input
    cout << "Please enter the number of values you want to sum: \n";
    int n = 0;
    cin >> n;
    if(n < 1)
        error("you have to sum at least one value!");
    cout << "Please enter some doubles (press '|' to stop): \n";
    double num_vec = 0;

    // store the input in the vectors
    while(cin >> num_vec)
    {
        values.push_back(num_vec);
        if(values.size() >= 2 && values.size() <= n)
        {
            diffs.push_back(num_vec - values[values.size() - 2]);
        }
    }

    if(diffs.size() < 2)
    {
        cout << "You need at least 2 values to get a vector of differences.\n";
    }
    else
    {
        cout << "Vector of differences: \n";
        for(int i = 0; i < diffs.size(); i++)
        {
            if(i == diffs.size() - 1)
            {
                cout << diffs[i] << '\n';
            }
            else
                cout << diffs[i] << ", ";
        }
    }

    if(n > values.size())
    {
        error("user asked for a sum of more numbers than there are in the vector.");
    }
    cout << "The sum of the first " << n << " numbers is: " << sum_vec(n) << ". \n";
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
