#include "ppp2/std_lib_facilities.h"

int main()
{
    cout << "How many pennies (1-cent coins) do you have?\n";
    int pennies = 0;
    cin >> pennies;
    cout << "How many nickles (5-cent coins) do you have?\n";
    int nickles = 0;
    cin >> nickles;
    cout << "How many dimes (10-cent coins) do you have?\n";
    int dimes = 0;
    cin >> dimes;
    cout << "How many quarters (25-cent coins) do you have?\n";
    int quarters = 0;
    cin >> quarters;
    cout << "How many half dollars (50-cent coins) do you have?\n";
    int half_dollars = 0;
    cin >> half_dollars;
    cout << "How many one-dollar coins (100-cent coins) do you have?\n";
    int one_dollar = 0;
    cin >> one_dollar;
    if(pennies == 1)
        cout << "You have " << pennies << " pennie.\n";
    else
        cout << "You have " << pennies << " pennies.\n";
    if(nickles == 1)
        cout << "You have " << nickles << " nickle.\n";
    else
        cout << "You have " << nickles << " nickles.\n";
    if(dimes == 1)
        cout << "You have " << dimes << " dime.\n";
    else
        cout << "You have " << dimes << " dimes.\n";
    if(quarters == 1)
        cout << "You have " << quarters << " quarter.\n";
    else
        cout << "You have " << quarters << " quarters.\n";
    if(half_dollars == 1)
        cout << "You have " << half_dollars << " half dollar.\n";
    else
        cout << "You have " << half_dollars << " half dollars.\n";
    if(one_dollar == 1)
        cout << "You have " << one_dollar << " one-dollar coin.\n";
    else
        cout << "You have " << one_dollar << " one-dollars coins.\n";
    double sum = pennies + (nickles * 5) + (dimes * 10) + (quarters * 25) + (half_dollars * 50) + (one_dollar * 100);
    double dollars = sum / 100;
    cout << "The value of all your coins is " << sum << " cents or $" << dollars << ".\n";
}
