#include "ppp3/ppp.h"

vector<string> split(const string& s)
{
    string word;
    vector<string> result{};
    istringstream iss(s);

    while(iss >> word) { result.push_back(word); }

    return result;
}