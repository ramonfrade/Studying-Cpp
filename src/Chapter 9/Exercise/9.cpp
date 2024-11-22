#include "Chrono.h"
#include "ppp2/std_lib_facilities.h"

using Chrono::Date;
using Chrono::Month;

class Patron
{
public:
    // Default constructor
    Patron(string name, int card_number) : name_{name}, card_number_{card_number} {};

    // Modifying functions:
    void set_fee(float fee)
    {
        fee_ = fee;
    }

    // Non-modifying functions:
    const string& name() const
    {
        return name_;
    }

    const int& card_number() const
    {
        return card_number_;
    }

    const float& fee() const
    {
        return fee_;
    }

    const bool has_fee() const
    {
        return fee_ > 0;
    }

private:
    string name_;
    int card_number_;
    float fee_ = 0;
};

bool operator==(const Patron& a, const Patron& b)
{
    return a.card_number() == b.card_number();
}

bool operator!=(const Patron& a, const Patron& b)
{
    return !(a == b);
}

enum class Genre
{
    fiction,
    nonfiction,
    periodical,
    bibliography,
    children
};

class Book
{

public:
    Book(string isbn, string title, string author, Date copyright, Genre g); //constructor

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

    const Genre& genre() const
    {
        return genre_;
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
    Genre genre_;
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

Book::Book(string isbn, string title, string author, Date copyright, Genre genre)
    : isbn_{isbn}, title_{title}, author_{author}, copyright_{copyright}, genre_{genre}, co{false}
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

class Library
{

public:
    struct Transaction
    {
        Book book;
        Patron patron;
        Date date;

        Transaction(Book b, Patron p, Date d) : book{b}, patron{p}, date{d} {};
    };

    //Modifying functions:
    void add_book(const Book& book)
    {
        books.push_back(book);
    }

    void add_patron(const Patron& patron)
    {
        patrons.push_back(patron);
    }

    void check_out(const Patron& patron, const Book& book, const Date& date);

    //Non-modifying functions:
    vector<Patron> get_debtors();

private:
    vector<Book> books{};
    vector<Patron> patrons{};
    vector<Transaction> transactions{};
};

void Library::check_out(const Patron& patron, const Book& book, const Date& date)
{
    int i = 0;
    //check if patron is registered
    while(patron != patrons[i])
    {
        i++;
        if(i == patrons.size())
            error("check_book: patron is not registered");
    }
    i = 0;
    //check if book is registered
    while(book != books[i])
    {
        i++;
        if(i == books.size())
            error("check_book: book is not registered");
    }

    //check if patron owes a fee
    if(patron.has_fee())
        error("check_book: user owes a fee");
    else
    {
        transactions.push_back(Transaction(book, patron, date));
    }
};

vector<Patron> Library::get_debtors()
{
    vector<Patron> debtors{};
    for(int i = 0; i < transactions.size(); i++) { debtors.push_back(transactions[i].patron); }
    return debtors;
};
