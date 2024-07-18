#include "PPP2/std_lib_facilities.h"

vector<int> char_string(const vector<string>& v)
{
    if(v.size() == 0)
        error("the vector must have at least 1 element");
    vector<int> chars;
    for(string s : v)
    {
        int string_size = s.size();
        chars.push_back(string_size);
    }
    return chars;
}

string find_long(const vector<string>& v)
{
    string big;
    int longest = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(i == 0)
        {
            longest = v[i].size();
            big = v[i];
        }

        if(v[i].size() > longest)
        {
            longest = v[i].size();
            big = v[i];
        }
    }
    return big;
}

string find_short(const vector<string>& v)
{
    if(v.size() == 0)
        error("the vector must have at least 1 element");
    string small;
    int shortest = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(i == 0)
        {
            shortest = v[i].size();
            small = v[i];
        }

        if(v[i].size() < shortest)
        {
            shortest = v[i].size();
            small = v[i];
        }
    }
    return small;
}

string first_word(vector<string> v)
{
    if(v.size() == 0)
        error("the vector must have at least 1 element");
    sort(v);
    return v[0];
}

string last_word(vector<string> v)
{
    if(v.size() == 0)
        error("the vector must have at least 1 element");
    sort(v);
    return v[v.size() - 1];
}

void print(const vector<string>& words, const vector<int>& v)
{
    for(int i = 0; i < words.size(); i++) { cout << words[i] << " have " << v[i] << " characters.\n"; }
    return;
}

int main()
try
{
    vector<string> words{"ramon", "fluminense", "football", "quit", "pokemon", "quit", "messi"};
    vector<int> v = char_string(words);
    print(words, v);
    cout << "Smallest word is: " << find_short(words) << '\n'
         << "Largest word is: " << find_long(words) << '\n'
         << "First word is: " << first_word(words) << '\n'
         << "Last word is: " << last_word(words) << '\n';
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