#include "ppp2/std_lib_facilities.h"

int main()
{
    int min = 1;
    int max = 100;
    int number = 50;
    int range = max - min;
    int half = range / 2;
    int question = 1;
    char answer = '\0';

    cout << "Let's play a game! Think of a number between " << min << " and " << max << '\n';
    while(max != min)
    {

        range = max - min;
        if(range == 1)
        {
            number = max;
        }
        else
        {
            number = min + range / 2;
        }

        cout << question++ << ". Is the number you are thinking less than " << number << "? (answer with 'y' or 'n')\n";
        cin >> answer;

        if(answer == 'y')
        {
            max = number - 1;
        }
        else if(answer == 'n')
        {
            min = number;
        }
    }
    cout << "Your number is " << min << "!\n";
    cout << "I needed " << question << " guesses";
}
