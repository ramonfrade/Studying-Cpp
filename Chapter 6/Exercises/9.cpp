#include "../../../std_lib_facilities.h"

vector<int> num{};
vector<string> num_words{"thousand", "hundred", "ten", "one"};

string plural(int x, string quantity)
{
    if (x != 1)
    {
        return quantity + 's';
    }
    else
        return quantity;
    if (x < 0)
    {
        error("plural() can handle only positive numbers");
    }
}

int get_value()
{
    int value = 0;
    int x = 1;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        value += num[i] * x;
        x *= 10;
    }
    return value;
}

void check_num()
{
    switch (num.size())
    {
    case 4:
        cout << get_value() << " is ";
        for (int i = 0; i < num.size(); i++)
        {
            if (i == num.size() - 1)
            {
                cout << num[i] << ' ' << plural(num[i], num_words[i]) << ".\n";
            }
            else
                cout << num[i] << ' ' << plural(num[i], num_words[i]) << " and ";
        }
        break;
    case 3:
        cout << get_value() << " is ";

        for (int i = 0; i < num.size(); i++)
        {
            if (i == num.size() - 1)
            {
                cout << num[i] << ' ' << plural(num[i], num_words[i+1]) << ".\n";
            }
            else
                cout << num[i] << ' ' << plural(num[i], num_words[i+1]) << " and ";
        }
        break;
    case 2:
        cout << get_value() << " is ";

        for (int i = 0; i < num.size(); i++)
        {
            if (i == num.size() - 1)
            {
                cout << num[i] << ' ' << plural(num[i], num_words[i+2]) << ".\n";
            }
            else
                cout << num[i] << ' ' << plural(num[i], num_words[i+2]) << " and ";
        }
        break;
    case 1:
        cout << get_value() << " is ";

        for (int i = 0; i < num.size(); i++)
        {
            cout << num[i] << ' ' << plural(num[i], num_words[i+3]) << ".\n";
        }
        break;
    default:
        error("number must be beetween 0 and 9999");
        break;
    }
}

int main()
try
{
    char ch;
    cout << "enter an integer with up to 4 digits, followed by a ';'.\n"
         << "enter 'q' to quit\n";
    while (cin >> ch)
    {
        if (ch == 'q')
        {
            return 0;
        }
        if (ch < '0' || ch > '9')
        {
            check_num();
            num = {};
        }
        else
            num.push_back(ch - '0');
    }
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