#include "../../../std_lib_facilities.h"

double ctof (double c)                                      // converts Celsius to Fahrenheit
{
    double f = 9.0/5 * c + 32;
    if (c < -273.15)
    {
        error("temperature below absolute zero!");
    }
    
    return f;
}

double ftoc (double f)                                      // converts Fahrenheit to Celsius
{
    double c = (f-32) / (9.0/5);
    if (c < -273.15)
    {
        error("temperature below absolute zero!");
    }
    return c;
}
    
    int main()
try {
        cout << "Enter a Celsius or Fahrenheit temperature and I will convert to the other. (enter the temperature followed by 'c' for Celsius and 'f' for Fahrenheit) \n";
        double num = 0;                         // declare input variable
        char temp = ' ';
        double result = 0;
        cin >> num >> temp;

        switch (temp)
        {
        case 'c':
            result = ctof(num);
            cout << num << " Celsius is " << result << " Fahrenheit \n";
            break;
        case 'f':
            result = ftoc(num);
            cout << num << " Fahrenheit is " << result << " Celsius \n";
            break;
        default:
            error("invalid temperature! type 'c' or 'f'");
            break;
        }                            
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