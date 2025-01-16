#include "ppp2/std_lib_facilities.h"

void quad_equa(double a, double b, double c) // solves a quad equation
{
    double delta = b * b - 4 * a * c;
    double x1 = (-b + sqrt(delta)) / (2 * a);
    double x2 = (-b - sqrt(delta)) / (2 * a);

    if(delta < 0)
    {
        cout << "no real roots. \n";
    }
    else if(delta == 0)
    {
        cout << x1 << " is the root. \n";
    }
    else
    {
        cout << x1 << " and " << x2 << " are the roots.\n";
    }
}

int main()
try
{
    cout << "Enter the values of a, b and c of a quadratic equation:\n";

    double a, b, c;
    while(cin >> a >> b >> c) { quad_equa(a, b, c); }
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
