#include "ppp3/ppp.h"

int main()
{
    ifstream ifs("13.txt");
    if(!ifs)
    {
        error("cant open input file");
    }

    char c;

    int count_alpha = 0;
    int count_digit = 0;
    int count_alnum = 0;
    int count_punct = 0;
    int count_cntrl = 0;
    int count_lower = 0;
    int count_upper = 0;
    int count_xdigit = 0;
    int count_space = 0;
    int count_print = 0;
    int count_graph = 0;

    while(ifs.get(c))
    {
        if(isalpha(c))
        {
            count_alpha++;
        }
        if(isdigit(c))
        {
            count_digit++;
        }
        if(isalnum(c))
        {
            count_alnum++;
        }
        if(ispunct(c))
        {
            count_punct++;
        }
        if(iscntrl(c))
        {
            count_cntrl++;
        }
        if(islower(c))
        {
            count_lower++;
        }
        if(isupper(c))
        {
            count_upper++;
        }
        if(isxdigit(c))
        {
            count_xdigit++;
        }
        if(isspace(c))
        {
            count_space++;
        }
        if(isprint(c))
        {
            count_print++;
        }
        if(isgraph(c))
        {
            count_graph++;
        }
    }

    cout << "Character Classifications counts:\n";
    cout << "Alphanumeric: " << count_alnum << '\n';
    cout << "Alphabetic: " << count_alpha << '\n';
    cout << "Digit: " << count_digit << '\n';
    cout << "Lowercase: " << count_lower << '\n';
    cout << "Uppercase: " << count_upper << '\n';
    cout << "Whitespace: " << count_space << '\n';
    cout << "Punctuation: " << count_punct << '\n';
    cout << "Hex digit: " << count_xdigit << '\n';
    cout << "Printable: " << count_print << '\n';
    cout << "Control: " << count_cntrl << '\n';
    cout << "Graphic: " << count_graph << '\n';
}