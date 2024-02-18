#include "../../../std_lib_facilities.h"

int main()
{
    cout << "Enter an integer value:\n";
    int val = 0;
    cin >> val;
    if (val%2 > 0)
        cout << val << " is an odd number.\n";
    else
        cout << val << " is an even number.\n";
}