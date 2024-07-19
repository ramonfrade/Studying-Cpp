#include "ppp2/std_lib_facilities.h"

int main()
{
    int val1 = 0;
    int val2 = 0;
    cout << "Enter two integers values:\n";
    cin >> val1 >> val2;
    if(val1 < val2)
        cout << val1 << " is smaller than " << val2 << ".\n" << val2 << " is larger than " << val1 << ".\n";
    else if(val2 < val1)
        cout << val2 << " is smaller than " << val1 << ".\n" << val1 << " is larger than " << val2 << ".\n";
    cout << "The sum of these numbers is " << val1 + val2 << ".\n"
         << "The difference of these numbers is " << val1 - val2 << ".\n"
         << "The product of these numbers is " << val1 * val2 << ".\n"
         << "The ratio of these numbers is " << val1 / val2 << ".\n";
}
