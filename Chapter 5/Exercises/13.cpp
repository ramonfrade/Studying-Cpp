#include "../../../std_lib_facilities.h"

int bulls = 0;
int cows = 0;

// generate new random answer
vector<int> new_answer()
{
    vector<int> answer(4);
    answer[0] = randint(10);
    answer[1] = randint(10);
    if (answer[1] == answer[0])
    {
        answer[1] = randint(10);
    }

    answer[2] = randint(10);
    if (answer[2] == answer[1] || answer[2] == answer[0])
    {
        answer[2] = randint(10);
    }

    answer[3] = randint(10);
    if (answer[3] == answer[2] || answer[3] == answer[1] || answer[3] == answer[0])
    {
        answer[3] = randint(10);
    }

    return answer;
}

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

// checking guess
bool check_guess(vector<int> guess, vector<int> answer)
{
    // checking bulls
    for (int i = 0; i < answer.size(); i++)
    {
        if (guess[i] == answer[i])
        {
            ++bulls;
        }
    }

    // checking cows
    for (int i = 0; i < answer.size(); i++)
    {
        if (guess[0] == answer[i] && guess[0] != answer[0])
        {
            ++cows;
        }
        else if (guess[1] == answer[i] && guess[1] != answer[1])
        {
            ++cows;
        }
        else if (guess[2] == answer[i] && guess[2] != answer[2])
        {
            ++cows;
        }
        else if (guess[3] == answer[i] && guess[3] != answer[3])
        {
            ++cows;
        }
    }

    // returning value and giving output
    if (bulls == 4)
    {
        return true;
    }
    if (bulls == 1)
    {
        cout << bulls << " bull and ";
    }
    else
        cout << bulls << " bulls and ";
    if (cows == 1)
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
    // presenting the game
    cout << "Let's play a game, it is called Bulls and Cows!\n";
    int x = 0;

    // generating seed
    cout << "Enter a seed to generate random numbers: (just type any number) (type '|' if you want to stop)\n";
    int seed = 0;
    cin >> seed;
    if (!cin)
    {
        return 0;
    }
    seed_randint(seed);
    vector<int> answer = new_answer();

    // playing the game
    cout << "Enter a sequence of 4 different integers in the range 0 to 9: (e.g., 1234 but not 1122) (type 'q' if you want to give up)\n";
    while (cin >> x)
    {
        if (x > 9999 || x < 0)
        {
            error("The number must be between 0000 and 9999");
        }
        // resetting count
        bulls = 0;
        cows = 0;
        // checking if the answer is correct
        vector<int> guess = vec_guess(x);
        bool correct = check_guess(guess, answer);
        if (correct == true)
        {
            cout << "You got it right on the spot! Setting new solution...\n";
            answer = new_answer();
            cout << "Enter a sequence of 4 different integers in the range 0 to 9: (e.g., 1234 but not 1122) (type 'q' if you want to give up)\n";
        }
        
    }
    cout << "You gave up!\n";
    cout << "The answer was: ";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
        keep_window_open();
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