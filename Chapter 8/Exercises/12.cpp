#include "../../../std_lib_facilities.h"

void print_until_s(const vector<string> &v, const string &quit)
{
    for (const string &s : v)
    {
        if (s == quit)
            return;
        cout << s << '\n';
    }
}

void print_until_ss(const vector<string> &v, const string &quit)
{
    int times = 0;
    for (const string &s : v)
    {
        if (s == quit)
        {
            ++times;
        }
        if (times > 1)
        {
            return;
        }
        cout << s << '\n';
    }
}

int main()
try
{
    vector<string> v{"ramon", "fluminense", "football", "quit", "pokemon", "quit", "messi"};
    print_until_s(v, "pokemon");
    print_until_ss(v, "quit");
}
catch (exception &e)
{
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...)
{
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}