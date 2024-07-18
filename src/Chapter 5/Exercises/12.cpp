#include "PPP2/std_lib_facilities.h"

vector<int> answer = {0, 7, 2, 5};
int bulls = 0;
int cows = 0;

// transform guess in vec
vector<int> vec_guess(int x)
{
    int x1 = x / 1000 % 100;
    int x2 = x / 100 % 10;
    int x3 = x / 10 % 10;
    int x4 = x % 10;

    vector<int> guess = {x1, x2, x3, x4};
    return guess;
}

bool check_guess(vector<int> guess, vector<int> answer)
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
         << "Enter a sequence of 4 different integers in the range 0 to 9 (e.g., 1234 but not 1122)\n";
    int x = 0;
    while(cin >> x)
    {
        if(x > 9999 || x < 0)
        {
            error("The number must be between 0000 and 9999");
        }
        bulls = 0;
        cows = 0;
        vector<int> guess = vec_guess(x);
        bool correct = check_guess(guess, answer);
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