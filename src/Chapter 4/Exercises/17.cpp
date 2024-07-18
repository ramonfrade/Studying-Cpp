#include "PPP2/std_lib_facilities.h"

int main()
{
    vector<string> words;
    string mode;
    int reps = 1;
    int max_reps = 1;
    cout << "Enter words: (Type '|' to stop)\n";
    for(string input; cin >> input;)
    {
        if(input == "|")
        {
            break;
        }
        else
            words.push_back(input);
    }

    sort(words);

    for(int i = 1; i < words.size(); i++)
    {
        if(words[i] == words[i - 1])
        {
            reps++;
        }
        else
        {
            reps = 1;
        }
        if(max_reps < reps)
        {
            mode = words[i];
            max_reps = reps;
        }
    }

    cout << "The min of the series is " << words[0] << ".\n";
    cout << "The max of the series is " << words[words.size() - 1] << ".\n";
    cout << "The mode of the series is " << mode << " with " << max_reps << " repetitions.\n";
}