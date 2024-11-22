#include "Chrono.h"
#include "ppp2/std_lib_facilities.h"

using Chrono::Date;
using Chrono::Month;

class Book
{

public:
    Book(string isbn, string title, string author, Date copyright); //constructor

    class Invalid_ISBN
    {
    };

    //modifying function members:
    void check_in()
    {
        co = true;
    }

    void check_out()
    {
        co = false;
    }

    // non-modifying function members:
    const string& isbn() const
    {
        return isbn_;
    }

    const string& title() const
    {
        return title_;
    }

    const string& author() const
    {
        return author_;
    }

    const Date& copyright() const
    {
        return copyright_;
    }

    const bool checked_out() const
    {
        return co;
    }

    bool is_isbn(const string& isbn);

private:
    string isbn_;
    string title_;
    string author_;
    Date copyright_;
    bool co;
};

//checks if it is in a n-n-n-x series, (n is an integer and x is a digit or letter)
bool Book::is_isbn(const string& isbn)
{
    int hyphen = 0;
    bool is_number{false};
    for(int i = 0; i < isbn.size(); i++)
    {
        char c{isbn[i]};

        if(hyphen < 3)
        {
            if(!isdigit(c))
            {
                if(c == '-' && is_number)
                {
                    ++hyphen;
                    is_number = false;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                is_number = true;
            }
        }
        else
        {
            if(i != isbn.size() - 1)
            {
                return false;
            }
            return isdigit(c) || isalpha(c);
        }
    }
    return false;
}

Book::Book(string isbn, string title, string author, Date copyright)
    : isbn_{isbn}, title_{title}, author_{author}, copyright_{copyright}, co{false}
{
    if(!is_isbn(isbn))
    {
        throw Invalid_ISBN{};
    }
}

bool operator==(const Book& a, const Book& b)
{
    if(a.isbn() == b.isbn())
    {
        return true;
    }
    else
        return false;
}

bool operator!=(const Book& a, const Book& b)
{
    return !(a.isbn() == b.isbn());
}

ostream& operator<<(ostream& os, const Book& a)
{
    return os << "Title: " << a.title() << '\n' << "Author: " << a.author() << '\n' << "ISBN: " << a.isbn() << '\n';
}

int main()
try
{
    Book Flu{"7-7-0-5", "Fluminense", "Oscar Cox", Date{1902, Month::jul, 21}};
    Book Flu2 = Flu;
    cout << Flu;
    if(Flu == Flu2)
    {
        cout << "Equal\n";
    }
    else
        cout << "Not Equal\n";

    Book NotFlu{"7-7-7-7", "Fluminense", "Oscar Cox", Date{1902, Month::jul, 21}};
    if(NotFlu != Flu)
    {
        cout << "Not equal\n";
    }
    else
        cout << "Equal\n";
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