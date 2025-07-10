#include "ppp3/ppp.h"

int main()
{
    ifstream ifs("14input.txt");
    if(!ifs)
    {
        error("cant open input file");
    }

    ofstream ofs("14output.txt");
    if(!ofs)
    {
        error("cant open output file");
    }

    float number = 0.0;
    int count = 0;

    ofs << scientific << setprecision(8);

    while(ifs >> number)
    {
        ofs << left << setw(20) << number;
        count++;

        if(count == 4)
        {
            ofs << '\n';
            count = 0;
        }
    }
}