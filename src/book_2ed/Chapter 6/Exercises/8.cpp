#include "ppp2/std_lib_facilities.h"

vector<char> answer = {'r', 'a', 'm', 'o'};
int bulls = 0;
int cows = 0;

bool check_guess(vector<char> guess)
{
    // checking bulls
    for(int i = 0; i < answer.size(); i++)
    {
        if(guess[i] == answer[i])
        {
            ++bulls;
        }
    }

    // checking cows
    for(int i = 0; i < answer.size(); i++)
    {
        if(guess[0] == answer[i] && guess[0] != answer[0])
        {
            ++cows;
        }
        else if(guess[1] == answer[i] && guess[1] != answer[1])
        {
            ++cows;
        }
        else if(guess[2] == answer[i] && guess[2] != answer[2])
        {
            ++cows;
        }
        else if(guess[3] == answer[i] && guess[3] != answer[3])
        {
            ++cows;
        }
    }

    // returning value and giving output
    if(bulls == 4)
    {
        return true;
    }
    if(bulls == 1)
    {
        cout << bulls << " bull and ";
    }
    else
        cout << bulls << " bulls and ";
    if(cows == 1)
    {
        cout << cows << " cow!\n";
    }
    else
        cout << cows << " cows!\n";

    return false;
}

int main()
try
{
    cout << "Let's play a game, it is called Bulls and Cows!\n"
         << "Enter a sequence of 4 different letters (e.g., abcd but not aabb)\n";
    char c0, c1, c2, c3;
    while(cin >> c0 >> c1 >> c2 >> c3)
    {
        if(c0 < 'a' || c0 > 'z' || c1 < 'a' || c1 > 'z' || c2 < 'a' || c2 > 'z' || c3 < 'a' || c3 > 'z')
        {
            error("character not supported");
        }
        vector<char> guess(4);
        guess[0] = c0;
        guess[1] = c1;
        guess[2] = c2;
        guess[3] = c3;

        bulls = 0;
        cows = 0;
        bool correct = check_guess(guess);
        if(correct == true)
        {
            cout << "You got it right on the spot!\n";
            return 0;
        }
    }
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
