#include "ppp3/ppp.h"

vector<string> split(const string& s, const string& w)
{
    string word;
    vector<string> result{};
    for(char c : s)
    {
        if(isspace(c) || w.find(c) != string::npos)
        {
            if(!word.empty())
            {
                result.push_back(word);
                word = "";
            }
        }
        else
            word += c;
    }
    if(!word.empty())
    {
        result.push_back(word);
    }

    return result;
}