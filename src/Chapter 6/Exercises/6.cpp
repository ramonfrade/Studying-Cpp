/*
GRAMMAR EXERCISE

Sentence:
          Noun Verb                   	     // e.g., C++ rules
          Article Noun Verb		             // e.g., the C++ rules
          Sentence Conjunction Sentence      // e.g., the birds fly but the fish swim
Conjunction:
          "and"
          "or"
          "but"
Article:
          "the"
Noun:
          "birds"
          "fish"
          "C++"
Verb:
          "rules"
          "fly"
          "swim"
*/

#include "ppp2/std_lib_facilities.h"

// defining class
class string_stream
{
public:
    string_stream();
    string get();
    void putback(string s);

private:
    bool full;
    string buffer;
};

string_stream::string_stream() : full(false), buffer("\0") {}

string string_stream::get()
{
    if(full)
    {
        full = false;
        return buffer;
    }

    string s;
    cin >> s;

    return s;
}

void string_stream::putback(string s)
{
    if(full)
        error("putback() buffer full");
    buffer = s;
    full = true;
}

//---------------------------------------------------------------
string_stream ss;

//---------------------------------------------------------------

bool conjunctio()
{
    vector<string> conjunction{"and", "or", "but"};
    bool is_conjunction = false;
    string s = ss.get();
    for(int i = 0; i < conjunction.size(); i++)
    {
        if(s == conjunction[i])
        {
            is_conjunction = true;
            break;
        }
    }

    if(!is_conjunction)
    {
        ss.putback(s);
    }

    return is_conjunction;
}

bool article()
{
    vector<string> article{"the"};
    bool is_article = false;
    string s = ss.get();
    for(int i = 0; i < article.size(); i++)
    {
        if(s == article[i])
        {
            is_article = true;
            break;
        }
    }

    if(!is_article)
    {
        ss.putback(s);
    }

    return is_article;
}

bool noun()
{
    vector<string> noun{"birds", "fish", "C++"};
    bool is_noun = false;
    string s = ss.get();
    for(int i = 0; i < noun.size(); i++)
    {
        if(s == noun[i])
        {
            is_noun = true;
            break;
        }
    }

    if(!is_noun)
    {
        ss.putback(s);
    }

    return is_noun;
}

bool verb()
{
    vector<string> verb{"rules", "fly", "swim"};
    bool is_verb = false;
    string s = ss.get();
    for(int i = 0; i < verb.size(); i++)
    {
        if(s == verb[i])
        {
            is_verb = true;
            break;
        }
    }

    if(!is_verb)
    {
        ss.putback(s);
    }

    return is_verb;
}

bool sentence()
{
    if((noun() || (article() && noun())) && verb())
    {
        if(conjunctio())
        {
            return sentence();
        }
        else
            return true;
    }
    else
        ss.get();
    return false;
}

int main()
try
{
    bool end = false;
    bool is_ok = false;
    while(!end)
    {
        string s = ss.get();
        if(s == ".")
        {
            if(is_ok)
            {
                cout << "OK\n";
            }
            else
                cout << "Not OK\n";
        }
        else
            ss.putback(s);

        is_ok = sentence();
    }
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
