#include "ppp2/std_lib_facilities.h"

int main()
{
    cout << "Let's play a game! Think of a number between 1 and 100.\n";
    int max = 100;
    int min = 1;
    int range = max - min;
    int half = range / 2;
    int number = 50;
    char answer;
    int question = 1;

    while(max != min)
    {
        range = max - min;
        if(range == 1)
        {
            number = max;
        }
        else
            number = min + range / 2;

        cout << question << ". Is your number less than " << number << "? (answer with 'y' or 'n')\n";
        cin >> answer;
        if(answer == 'y')
        {
            max = number - 1;
            question++;
        }
        else if(answer == 'n')
        {
            min = number;
            question++;
        }
        else
            cout << "Please answer with 'y' or 'n'.\n";
    }
    cout << "Your number is " << min << "!\n";
    cout << "I needed " << question << " guesses!\n";
    keep_window_open();
    return 0;
}
