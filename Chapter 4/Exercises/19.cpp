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

    cout << "Names and scores are:\n";
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << " " << scores[i] << '\n';
    }
    
}
