#include "ppp2/std_lib_facilities.h"

int factorial(int a)
{
    if(a == 0)
    {
        return 1;
    }
    else if(a < 0)
    {
        error("factorial of negative numbers not defined");
    }
    else
        for(int i = a - 1; i > 0; i--) { a *= i; }
    return a;
}

int permutation(int a, int b)
{
    if(a == 0 && b == 0)
    {
        error("No permutations found for 0");
    }
    if(a < b)
    {
        error("not enough numbers for set size");
    }

    return factorial(a) / factorial(a - b);
}

int combination(int a, int b)
{
    return permutation(a, b) / factorial(b);
}

int main()
try
{
    int a;
    int b;
    char ch;
    while(cin)
    {
        cout << "Enter two integers to get permutations or combinations from:\n";
        cin >> a >> b;
        if(a == '|' || b == '|')
        {
            return 0;
        }

        if(!cin)
        {
            cout << "Please enter an integer!\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
        {
            {
                cout << "Enter 'p' for permutation or 'c' for combination:  (type '|' to stop)\n";
                cin >> ch;
                switch(ch)
                {
                    case 'p': cout << "P(" << a << ", " << b << ") = " << permutation(a, b) << '\n'; break;
                    case 'P': cout << "P(" << a << ", " << b << ") = " << permutation(a, b) << '\n'; break;
                    case 'c': cout << "C(" << a << ", " << b << ") = " << combination(a, b) << '\n'; break;
                    case 'C': cout << "C(" << a << ", " << b << ") = " << combination(a, b) << '\n'; break;
                    case '|': return 0;
                    default: cout << "Please enter 'p' or 'c'.\n"; break;
                }
            }
        }
    }
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
