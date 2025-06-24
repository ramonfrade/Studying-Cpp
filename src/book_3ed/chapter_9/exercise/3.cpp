#include "ppp3/ppp.h"

bool isvowel(const char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O'
       || c == 'U')
    {
        return true;
    }
    return false;
}

int main()
{
    string filename;
    cout << "Please enter the name of input file:\n";
    cin >> filename;
    ifstream ifs{filename};
    if(!ifs)
        error("cant open input file");

    string newfile = "new_disemvowels.txt";
    ofstream ofs{newfile};
    if(!ofs)
        error("cant open output file");

    string line;
    bool first_line = true;

    while(getline(ifs, line))
    {
        if(!first_line)
        {
            ofs << '\n';
        }

        string temp_line;
        for(char c : line)
        {
            if(!isvowel(c))
            {
                temp_line += c;
            }
        }

        string final_line;
        if(!temp_line.empty())
        {
            final_line += temp_line[0];

            for(size_t i = 1; i < temp_line.length(); ++i)
            {
                if(temp_line[i] == ' ' && temp_line[i - 1] == ' ')
                {
                    continue;
                }
                final_line += temp_line[i];
            }
        }
        ofs << final_line;
        first_line = false;
    }
}