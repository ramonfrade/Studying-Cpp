#include "ppp3/ppp.h"

vector<string> classifyChar(const char c)
{

    vector<string> categories;

    if(isalpha(c))
    {
        categories.push_back("letter");
    }
    if(isdigit(c))
    {
        categories.push_back("digit");
    }
    if(isalnum(c))
    {
        categories.push_back("alphanumeric");
    }
    if(ispunct(c))
    {
        categories.push_back("punctuation");
    }
    if(iscntrl(c))
    {
        categories.push_back("control");
    }
    if(islower(c))
    {
        categories.push_back("lowercase");
    }
    if(isupper(c))
    {
        categories.push_back("uppercase");
    }
    if(isxdigit(c))
    {
        categories.push_back("hexadecimal digit");
    }
    if(isspace(c))
    {
        categories.push_back("whitespace");
    }
    if(isprint(c))
    {
        categories.push_back("printable");
    }
    if(isgraph(c))
    {
        categories.push_back("graphical");
    }

    return categories;
}

int main()
{
    cout << "Enter strings, press Ctrl+Z to stop:\n";

    string input;
    while(getline(cin, input))
    {
        for(char c : input)
        {
            cout << "'" << c << "': ";
            vector<string> classifications = classifyChar(c);
            for(int i = 0; i < classifications.size(); i++)
            {
                if(i == classifications.size() - 1)
                {
                    cout << classifications[i] << '\n';
                }
                else
                    cout << classifications[i] << ", ";
            }
        }
    }
}