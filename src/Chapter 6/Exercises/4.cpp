#include "ppp2/std_lib_facilities.h"

class Name_value // declaring class
{
public:
    string name;
    int value;

    Name_value(string words, int val) : name(words), value(val) {}
};

int main()
try
{
    vector<Name_value> nv_vec;

    string name;
    int score;

    cout << "Enter the name and the score (Write NoName 0 to stop):\n";

    while(cin >> name >> score)
    {
        if(name == "NoName" && score == 0)
        {
            break;
        }

        if(nv_vec.size() == 0)
        {
            nv_vec.push_back(Name_value(name, score));
        }
        else
        {
            for(int i = 0; i < nv_vec.size(); i++)
            {
                if(name == nv_vec[i].name)
                {
                    simple_error("ERROR: This name already has a score.\n");
                }
            }
            nv_vec.push_back(Name_value(name, score));
        }
    }

    cout << "Names and scores are:\n";
    for(int i = 0; i < nv_vec.size(); i++) { cout << nv_vec[i].name << ', ' << nv_vec[i].value << '\n'; }
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
