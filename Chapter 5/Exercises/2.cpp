#include "../../../std_lib_facilities.h"

double ctok(double c)                   // converts Celsius to Kelvin
{
        int k = c + 273.15;
        return k;
}
int main()
{
        cout << "Enter a Celsius temperature and I will convert to Kelvin. \n";
        double c = 0;                         // declare input variable
        cin >> c;                                // retrieve temperature to input variable
        double k = ctok(c);           // convert temperature
        cout << k << '\n';                 // print out temperature
}