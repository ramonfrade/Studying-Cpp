#include "../../../std_lib_facilities.h"

double ctok(double c)                   // converts Celsius to Kelvin
{
        double k = c + 273.15;
        if (c < -273.15)
        {
            error("temperature below absolute zero!");
        }
        
        return k;
}
int main()
try {
        cout << "Enter a Celsius temperature and I will convert to Kelvin. \n";
        double c = 0;                         // declare input variable
        cin >> c;                                // retrieve temperature to input variable
        double k = ctok(c);           // convert temperature
        cout << k << '\n';                 // print out temperature
}
catch(exception& e){
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
}
catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
}