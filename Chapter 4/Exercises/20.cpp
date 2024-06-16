#include "../../../std_lib_facilities.h"

int main()
{
    vector<string>names{};
    vector<int>scores{};
    
    string name;
    int score;

    cout << "Enter the name and the score (Write NoName 0 to stop):\n";

    while (cin >> name >> score)
    {
    if (name == "NoName" && score == 0)
    {
        break;
    }
    
    if (names.size() == 0)
    {
        names.push_back(name);
        scores.push_back(score);
    }
    else
    {
    for (int i = 0; i < names.size(); i++)
    {
        if (name == names[i])
        {
            simple_error("ERROR: This name already has a score.\n");
        }
    }
        names.push_back(name);
        scores.push_back(score);
    }
    }

    cout << "All names and scores are:\n";
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << " " << scores[i] << '\n';
    }

    cout << "Enter a name and I will output the corresponding score: (Type '|' to stop) \n";
    string name_score;
    while (cin >> name_score)
    {
        bool find_name = true;

        if (name_score == "|")
        {
            break;
        }

        for (int i = 0; i < names.size(); i++)
    {
        if (name_score == names[i])
        {
            cout << names[i] << " " << scores[i] << '\n';
            find_name = true;
            break;
        }
        else
        {
            find_name = false;
        }
    }
        if (find_name == false)
        {
            cout << "Name not found. \n";
        }
    }
}
