#include "ppp2/std_lib_facilities.h"

vector<int> new_rev_sort(const vector<int>& v)
{
    vector<int> new_vec;
    for(int i = v.size() - 1; i >= 0; i--) { new_vec.push_back(v[i]); }
    return new_vec;
}

void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void rev_sort(vector<int>& v)
{
    int x = v.size() - 1;
    for(int i = 0; i < x; i++)
    {
        swap(v[i], v[x]);
        x--;
    }
    return;
}

void print(const vector<int>& v)
{
    cout << "Vector elements: \n";
    for(int i = 0; i < v.size(); i++) { cout << v[i] << '\n'; }
}

int main()
try
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> rv = new_rev_sort(v);
    rev_sort(v);
    print(v);
    print(rv);
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
