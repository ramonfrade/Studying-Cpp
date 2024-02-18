#include "../../../std_lib_facilities.h"

int main()
{
    cout << "Enter a spelled-out number:\n";
    string spelled_number;
    while (cin >> spelled_number){
        if (spelled_number == "zero" || spelled_number == "Zero" || spelled_number == "0")
            cout << "0\n";
        else if (spelled_number == "one" || spelled_number == "One" || spelled_number == "1")
            cout << "1\n";
        else if (spelled_number == "two" || spelled_number == "Two" || spelled_number == "2")
            cout << "2\n";
        else if (spelled_number == "three" || spelled_number == "Three" || spelled_number == "3")
            cout << "3\n";
        else if (spelled_number == "four" || spelled_number == "Four" || spelled_number == "4")
            cout << "4\n";
        else
            cout << "not a number I know\n";
    }
}