#include "ppp3/ppp.h"

void tolowers(string& s) // put s into lowercase
{
    for(char& x : s) x = tolower(x);
}

int main()
{
    string filename;
    cout << "Please enter the name of input file:\n";
    cin >> filename;
    ifstream ifs{filename};
    if(!ifs)
        error("cant open input file");

    string newfile = "lowered_";
    newfile += filename;
    ofstream ofs{newfile};
    if(!ofs)
        error("cant open output file");

    for(string s; ifs >> s;)
    {
        tolowers(s);
        ofs << s << ' ';
    }
}