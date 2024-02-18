#include "../../../std_lib_facilities.h"

int main(){
    double val1 = 0;
    double val2 = 0;
    char operation = '\0';

    cout << "Enter two values followed by an operator. (ex: 10.5, 20, +)\n";
    while (cin >> val1 >> val2 >> operation)
    if (operation == '+')
    {
        cout << "The sum of " << val1 << " and " << val2 << " is " << val1+val2 << ".\n";
    }
    else if (operation == '-')
    {
        cout << "The difference of " << val1 << " and " << val2 << " is " << val1-val2 << ".\n";
    }
    else if (operation == '/')
    {
        cout << "The division of " << val1 << " and " << val2 << " is " << val1/val2 << ".\n";
    }
    else if (operation == '*')
    {
        cout << "The product of " << val1 << " and " << val2 << " is " << val1*val2 << ".\n";
    }
    else
        cout << "Please enter a valid operator ('+', '-', '/', '*')\n";
}