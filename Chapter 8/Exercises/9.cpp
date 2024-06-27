#include "../../../std_lib_facilities.h"

double index(const vector<double> &price, const vector<double> &weight)
{
    if (price.size() != weight.size())
        error("Different size vectors");

    double sum = 0;
    for (int i = 0; i < price.size(); i++)
    {
        sum += price[i] * weight[i];
    }
    return sum;
}

int main()
try
{
    vector<double> price = {1.2, 2.3, 2.1, 7.7, 2, 15};
    vector<double> weight = {1, 2.2, 3.1, 4.6, 5.1, 0.75,};
    cout << index(price, weight);
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