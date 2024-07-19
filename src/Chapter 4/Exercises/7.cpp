#include "ppp2/std_lib_facilities.h"

vector<string> string_values = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string inputValues = "Numbers must be digits from 0 to 9 (either digit or spelled-out)\n";

int convertStringToInt(string digit)
{
    for(int i = 0; i < string_values.size(); i++)
    {
        if(digit == string_values[i])
        {
            return i;
        }
    }
    cout << "Error: value not in vector\n";
    cout << inputValues;
    return -1;
}

vector<char> validOperators = {'+', '-', '*', '/'};
string inputOperator = "enter a valid operator ('+','-','*','/')\n";

bool checkValidOperator(char oper)
{
    for(char o : validOperators)
    {
        if(oper == o)
        {
            return true;
        }
    }
    cout << inputOperator;
    return false;
}

int main()
{
    string input
        = "Write two single digit number (either digit or spelled out) followed by an operator ('+','-','*','/')\n";
    cout << input;

    int op, op1, op2;
    vector<int> integerOperands(2);
    string opstring;
    char operation = ' ';
    bool validOperator = false;

    while(true)
    {
        int i = 0;
        while(i < integerOperands.size())
        {
            if(cin >> op)
            {
                integerOperands[i] = op;
                ++i;
            }
            else
            {
                cin.clear();
                cin >> opstring;
                if(opstring == "|")
                {
                    return 0;
                }
                else
                {
                    int result = convertStringToInt(opstring);
                    if(result != -1)
                    {
                        integerOperands[i] = result;
                        ++i;
                    }
                }
            }
        }
        while(!validOperator)
        {
            if(cin >> operation)
            {
                validOperator = checkValidOperator(operation);
            }
            else
                cout << inputOperator;
        }
        validOperator = false;
        op1 = integerOperands[0];
        op2 = integerOperands[1];

        switch(operation)
        {
            case '+': cout << "The sum of " << op1 << " and " << op2 << " is " << op1 + op2 << ".\n"; break;
            case '-': cout << "The difference of " << op1 << " and " << op2 << " is " << op1 - op2 << ".\n"; break;
            case '*': cout << "The product of " << op1 << " and " << op2 << " is " << op1 * op2 << ".\n"; break;
            case '/':
                if(op2 == 0)
                    cout << "ERROR: Division by 0\n";
                else
                    cout << "The division of " << op1 << " and " << op2 << " is " << op1 / op2 << ".\n";
                break;
            default: cout << "The operator " << operation << " is not supported!\n"; break;
        }
        cout << input;
        cin.clear();
    }

    return 0;
}
