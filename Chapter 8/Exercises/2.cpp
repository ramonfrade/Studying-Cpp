#include "../../../std_lib_facilities.h"

void print(const string &output, const vector<int> &v)
{
    cout << output << '\n';
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << '\n';
    }
}