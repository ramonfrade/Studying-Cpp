#include "../../../std_lib_facilities.h"

double maxv(const vector<double> &v)
{
    if (v.size() == 0)
        error("vector must have at least 1 element");
    double num = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0 || v[i] > num)
        {
            num = v[i];
        }
    }
    return num;
}

int main()
try
{
    vector<double> v = {-5, 7.7, 7, 2, 81, 43, 12.3};
    cout << maxv(v);
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