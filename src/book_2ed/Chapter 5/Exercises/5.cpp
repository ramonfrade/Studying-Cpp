#include "ppp2/std_lib_facilities.h"

double ctok(double c) // converts Celsius to Kelvin
{
    double k = c + 273.15;
    if(c < -273.15)
    {
        error("temperature below absolute zero!");
    }

    return k;
}

double ktoc(double k) // converts Kelvin to Celsius
{
    double c = k - 273.15;
    if(k < 0)
    {
        error("temperature below absolute zero!");
    }

    return c;
}

int main()
try
{
    cout << "Enter a Celsius or Kelvin temperature and I will convert to the other. (enter the temperature followed by "
            "'c' for Celsius and 'k' for Kelvin) \n";
    double num = 0; // declare input variable
    char temp = ' ';
    double result = 0;
    cin >> num >> temp;

    switch(temp)
    {
        case 'c':
            result = ctok(num);
            cout << num << " Celsius is " << result << " Kelvin \n";
            break;
        case 'k':
            result = ktoc(num);
            cout << num << " Kelvin is " << result << " Celsius \n";
            break;
        default: error("invalid temperature! type 'c' or 'k'"); break;
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
