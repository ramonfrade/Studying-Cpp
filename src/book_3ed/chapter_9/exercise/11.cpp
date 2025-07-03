#include "ppp3/ppp.h"

string revertString(const string& s)
{
    string reverted_s;

    for(int i = s.size() - 1; i >= 0; i--) { reverted_s += s[i]; }
    return reverted_s;
}

int main()
{
    string input;
    ifstream ifs("11.txt");
    if(!ifs)
        error("cant open input file");

    string output;

    while(getline(ifs, input))
    {
        output += input;
        output += '\n';
    }

    output = revertString(output);

    ofstream ofs("reverted11.txt");
    if(!ofs)
        error("cant open output file");

    ofs << output;
}