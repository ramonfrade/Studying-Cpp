#include "ppp3/ppp.h"

int main()
{
    string filename, keyword;
    cout << "Please enter the name of input file:\n";
    cin >> filename;
    cout << "Now enter the keyword: \n";
    cin >> keyword;
    ifstream ifs{filename};
    if(!ifs)
        error("cant open input file");

    string line;
    int number_of_lines = 1;
    while(getline(ifs, line))
    {
        if(line.find(keyword) != string::npos)
        {
            cout << "Line " << number_of_lines << ": " << line << '\n';
        }
        ++number_of_lines;
    }
}