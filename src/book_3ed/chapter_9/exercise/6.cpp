#include "ppp3/ppp.h"

string replacePunct(const string& s)
{
    string new_string;
    bool inQuotes = false;
    for(char c : s)
    {
        if(c == '"')
        {
            inQuotes = !inQuotes;
            new_string += c;
        }
        else if(ispunct(c) && !inQuotes)
        {
            new_string += ' ';
        }
        else
            new_string += c;
    }
    return new_string;
}

int main()
{
    cout << "Enter strings, press Ctrl+Z to stop:\n";

    string input;
    while(getline(cin, input)) { cout << replacePunct(input) << '\n'; }
}