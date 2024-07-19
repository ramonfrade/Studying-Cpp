#include "ppp2/std_lib_facilities.h"

vector<int> integers{};

int sum_vec(int n)
{
    int z = 0;
    for(int i = 0; i < n; i++) { z += integers[i]; }

    return z;
}

int main()
try
{
    cout << "Please enter the number of values you want to sum: \n";
    int n = 0;
    cin >> n;
    if(n < 1)
        error("you have to sum at least one value!");
    cout << "Please enter some integers (press '|' to stop): \n";
    int num_vec = 0;
    while(cin >> num_vec) { integers.push_back(num_vec); }

    if(n > integers.size())
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
