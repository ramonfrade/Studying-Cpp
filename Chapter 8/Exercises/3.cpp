#include "../../../std_lib_facilities.h"

void fibonacci(const int &x, const int &y, vector<int> &v, const int &n)
{
    if (n < 3)
        error("There must be at least two numbers in the sequence");
    v.push_back(x);
    v.push_back(y);
    for (int i = 2; i < n; i++)
    {
        v.push_back(v[i - 1] + v[i - 2]);
    }
}

void print(const string &output, const vector<int> &v)
{
    cout << output << '\n';
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << '\n';
    }
}

int main()
try
{
    cout << "Type the first number of the Fibonacci sequence: \n";
    int x = 0;
    cin >> x;

    cout << "Type the second number of the Fibonacci sequence: \n";
    int y = 0;
    cin >> y;

    cout << "Type how many numbers you want to the Fibonacci sequence: \n";
    int n = 0;
    cin >> n;

    vector<int> v;
    fibonacci(x, y, v, n);
    string s = "This is your Fibonacci sequence:";
    print(s, v);
}
catch (exception &e)
{
    cerr << "exception: " << e.what() << endl;
    char c;
    while (cin >> c && c != ';')
        ;
    return 1;
}
catch (...)
{
    cerr << "exception\n";
    char c;
    while (cin >> c && c != ';')
        ;
    return 2;
}