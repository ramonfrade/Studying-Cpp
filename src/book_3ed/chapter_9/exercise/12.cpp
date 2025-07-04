#include "ppp3/ppp.h"

int main()
{
    ifstream ifs("12.txt");
    if(!ifs)
    {
        error("cant open input file");
    }

    string line;
    vector<string> words;
    vector<int> wordsPerLine;

    while(getline(ifs, line))
    {
        istringstream iss(line);
        string word;
        int count = 0;

        while(iss >> word)
        {
            words.push_back(word);
            count++;
        }
        wordsPerLine.push_back(count);
    }

    reverse(words.begin(), words.end());
    reverse(wordsPerLine.begin(), wordsPerLine.end());

    ofstream ofs("output12.txt");
    if(!ofs)
    {
        error("cant open output file");
    }

    int index = 0;
    for(int numWords : wordsPerLine)
    {
        for(int i = 0; i < numWords; i++) { ofs << words[index++] << " "; }
        ofs << '\n';
    }
}