#include "ppp3/ppp.h"

string getBaseType(const string& input)
{
    if(input.substr(0, 2) == "0x" || input.substr(0, 2) == "0X")
    {
        return "hexadecimal";
    }
    else if(input.substr(0, 1) == "0")
    {
        return "octal";
    }
    else
        return "decimal";
}

int convertToDecimal(const string& input)
{
    istringstream is{input};
    int intValue = 0;

    if(input.substr(0, 2) == "0x" || input.substr(0, 2) == "0X")
    {
        is >> hex >> intValue;
    }
    else if(input.substr(0, 1) == "0")
    {
        is >> oct >> intValue;
    }
    else
        is >> intValue;

    return intValue;
}

int main()
{
    cout << "Enter integers, use 0 as prefix for octal base and 0x for hexadecimal. Presse Ctrl+Z to stop: \n";
    string input;
    while(cin >> input)
    {
        cout << left << setw(10) << input << setw(13) << getBaseType(input) << setw(14)
             << "converts to: " << convertToDecimal(input) << " decimal\n";
    }
}