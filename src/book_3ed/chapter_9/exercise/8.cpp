#include "ppp3/ppp.h"

string tolower(const string& s)
{
    string result;
    for(char c : s) { result += tolower(c); }
    return result;
}

// Replace punctuation characters with whitespace, do not modify within a pair of double quote.
string replacePunct(const string& s)
{
    string new_string;
    bool inQuotes = false;
    for(char c : s)
    {
        if(c == '"')
        {
            inQuotes = !inQuotes;
            new_string += c;
        }
        else if(ispunct(c) && !inQuotes && c != '-')
        {
            new_string += ' ';
        }
        else
            new_string += c;
    }
    return new_string;
}

// Replace "don't" with "do not", "can't" with "can not", etc...
string replaceWords(const string& s)
{
    string word = tolower(s);

    if(word == "don't")
    {
        return "do not";
    }
    if(word == "can't")
    {
        return "can not";
    }
    if(word == "won't")
    {
        return "will not";
    }
    if(word == "i'm")
    {
        return "i am";
    }
    if(word == "it's")
    {
        return "it is";
    }

    return word;
}

string processLine(const string& s)
{
    stringstream ss(s);
    string word;
    string result;
    while(ss >> word) { result += replaceWords(word) + ' '; }

    result = replacePunct(result);
    return result;
}

// Sort words in the input string
vector<string> sortInput(const string& s)
{
    stringstream ss(s);
    string word;
    vector<string> result;
    while(ss >> word) { result.push_back(word); }

    sort(result.begin(), result.end());
    return result;
}

int main()
{
    cout << "Enter a string\n";

    string input;
    vector<string> output;
    getline(cin, input);
    processLine(input);
    output = sortInput(processLine(input));

    ofstream ofs("8.txt");

    for(int i = 0; i < output.size(); i++) { ofs << output[i] << '\n'; }
}