#include "ppp2/std_lib_facilities.h"

int main()
{
    double miles = 0;
    cout << "Enter a number of miles:\n";
    while(cin >> miles)
    {
        double kilometers = miles * 1.6;
        cout << miles << " miles is " << kilometers << " kilometers\n";
    }
}
