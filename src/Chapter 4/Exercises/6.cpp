#include "PPP2/std_lib_facilities.h"

vector<string> string_values = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string input = "Write a number from 0 to 9 (digit or spelled-out).\n";

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
    cout << input;
    return -1;
}

string convertIntToString(int digit)
{
    if(digit < string_values.size())
    {
        return string_values[digit];
    }
    cout << "Error: digit not in vector\n";
    cout << input;
    return " ";
}

int main()
{
    cout << input;
    int value;
    string digit;
    bool validinput = true;

    while(validinput)
    {
        if(cin >> value)
        {
            if(convertIntToString(value) != " ")
            {
                cout << convertIntToString(value) << '\n';
            }
        }
        else
        {
            cin.clear();
            cin >> digit;
            if(digit == "|")
            {
                validinput = false;
            }
            else if(convertStringToInt(digit) != -1)
            {
                cout << convertStringToInt(digit) << '\n';
            }
        }
    }
}