#include "PPP2/std_lib_facilities.h"

int main()
{
    vector<string> options{"rock", "paper", "scissors"};
    char input;

    for(int i = 0; i < options.size(); i++)
    {
        cout << "Let's play rock, paper and scissors!\nType 'r' for rock, 'p' for paper or 's' for scissors.\n";
        cin >> input;

        if(input == 'r' || input == 'p' || input == 's')
        {
            cout << "I choose " << options[i] << "!\n";
        }

        switch(input)
        {
            case 'r':
                if(options[i] == "rock")
                {
                    cout << "It was a draw!\n\n";
                }
                else if(options[i] == "paper")
                {
                    cout << "I won!\n\n";
                }
                else if(options[i] == "scissors")
                {
                    cout << "You won!\n\n";
                }
                options.push_back("rock");
                break;
            case 'p':
                if(options[i] == "rock")
                {
                    cout << "You won!\n\n";
                }
                else if(options[i] == "paper")
                {
                    cout << "It was a draw!\n\n";
                }
                else if(options[i] == "scissors")
                {
                    cout << "I won!\n\n";
                }
                options.push_back("paper");
                break;
            case 's':
                if(options[i] == "rock")
                {
                    cout << "I won!\n\n";
                }
                else if(options[i] == "paper")
                {
                    cout << "You won!\n\n";
                }
                else if(options[i] == "scissors")
                {
                    cout << "It was a draw!\n\n";
                }
                options.push_back("scissors");
                break;
            default: cout << "That is not a valid option\n\n"; break;
        }
    }
}