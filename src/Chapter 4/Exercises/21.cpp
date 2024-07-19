#include "ppp2/std_lib_facilities.h"

int main()
{
    vector<string> names{};
    vector<int> scores{};

    string name;
    int score;

    cout << "Enter the name and the score (Write NoName 0 to stop):\n";

    while(cin >> name >> score)
    {
        if(name == "NoName" && score == 0)
        {
            break;
        }

        if(names.size() == 0)
        {
            names.push_back(name);
            scores.push_back(score);
        }
        else
        {
            for(int i = 0; i < names.size(); i++)
            {
                if(name == names[i])
                {
                    simple_error("ERROR: This name already has a score.\n");
                }
            }
            names.push_back(name);
            scores.push_back(score);
        }
    }

    cout << "All names and scores are:\n";
    for(int i = 0; i < names.size(); i++) { cout << names[i] << " " << scores[i] << '\n'; }

    cout << "Enter a score and I will output all the names with that score: (Type '|' to stop) \n";
    int int_score;
    while(cin >> int_score)
    {
        bool find_score = false;

        if(int_score == '|')
        {
            break;
        }

        for(int i = 0; i < scores.size(); i++)
        {
            if(int_score == scores[i])
            {
                cout << names[i] << " " << scores[i] << '\n';
                find_score = true;
            }
        }
        if(find_score == false)
        {
            cout << "score not found. \n";
        }
    }
}
