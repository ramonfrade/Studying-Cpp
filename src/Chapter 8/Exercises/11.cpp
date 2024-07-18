#include "PPP2/std_lib_facilities.h"

struct slmm // slmm == smallest, largest, mean and median
{
    double smallest;
    double largest;
    double mean;
    double median;
};

slmm result(vector<double> v)
{
    slmm d;
    if(v.size() == 0)
        error("the vector must have at least 1 element");

    if(v.size() % 2 == 0) // calculating the median
    {
        int half = v.size() / 2;
        d.median = (v[half] + v[half + 1]) / 2;
    }
    else
    {
        d.median = v[(v.size() - 1) / 2];
    }

    sort(v);
    d.smallest = v[0];
    d.largest = v[v.size() - 1];

    double sum = 0;
    for(int i = 0; i < v.size(); i++) // calculating the mean
    {
        sum += v[i];
    }
    d.mean = sum / v.size();
    return d;
}
int main()
try
{
    vector<double> v = {2, 3, 4.2, 12, 5.8, 7.7};
    slmm d = result(v);
    cout << "Smallest is: " << d.smallest << '\n'
         << "Largest is: " << d.largest << '\n'
         << "Mean is: " << d.mean << '\n'
         << "Median is: " << d.median << '\n';
}
catch(exception& e)
{
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch(...)
{
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}