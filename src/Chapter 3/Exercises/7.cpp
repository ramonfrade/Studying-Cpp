#include "ppp2/std_lib_facilities.h"

int main()
{
    cout << "Enter three words:\n";
    string word1;
    string word2;
    string word3;
    cin >> word1 >> word2 >> word3;
    if(word1 <= word2 && word2 <= word3)
        cout << word1 << ", " << word2 << ", " << word3 << '\n';
    else if(word1 <= word3 && word3 <= word2)
        cout << word1 << ", " << word3 << ", " << word2 << '\n';
    else if(word2 <= word1 && word1 <= word3)
        cout << word2 << ", " << word1 << ", " << word3 << '\n';
    else if(word2 <= word3 && word3 <= word1)
        cout << word2 << ", " << word3 << ", " << word1 << '\n';
    else if(word3 <= word1 && word1 <= word2)
        cout << word3 << ", " << word1 << ", " << word2 << '\n';
    else if(word3 <= word2 && word2 <= word1)
        cout << word3 << ", " << word2 << ", " << word1 << '\n';
}
