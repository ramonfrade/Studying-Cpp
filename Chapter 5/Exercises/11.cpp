#include "../../../std_lib_facilities.h"

int main()
{
    vector<int> fibonacci{1, 1};
    int x = 0;
    int y = 0;
    int sum = 0;

    for (int i = 0; i < fibonacci.size(); i++)
    {
        if (i >= 1)
        {
            x = fibonacci[fibonacci.size() - 1];
            y = fibonacci[fibonacci.size() - 2];
            sum = x + y;
            fibonacci.push_back(sum);
        }
        cout << fibonacci[i] << ' ';
        if (sum < 0)
        {
            cout << "\nThe largest Fibonacci number that fits in an int is: " << x << '\n';
            break;
        }
    }
}
