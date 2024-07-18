#include "PPP2/std_lib_facilities.h"

int main()
{
    cout << "Enter an operation followed by two operands, for example: '+ 300 100' or 'mul 3 50'\n";
    string operation;
    double val1;
    double val2;
    while(cin >> operation >> val1 >> val2)
    {
        if(operation == "+" || operation == "plus")
            cout << val1 + val2;
        else if(operation == "-" || operation == "minus")
            cout << val1 - val2 << '\n';
        else if(operation == "*" || operation == "mul")
            cout << val1 * val2 << '\n';
        else if(operation == "/" || operation == "div")
            cout << val1 / val2 << '\n';
    }
}