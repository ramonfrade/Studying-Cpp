#include "ppp2/std_lib_facilities.h"

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

int main()
try
{
    Patron Ramon("Ramon", 775);
    if(Ramon.has_fee())
    {
        cout << Ramon.name() << " owes a fee of " << Ramon.fee() << '\n';
    }
    else
        cout << Ramon.name() << " does not owe a fee\n";

    Patron Bjarne("Bjarne", 1234);
    Bjarne.set_fee(500);
    if(Bjarne.has_fee())
    {
        cout << Bjarne.name() << " owes a fee of " << Bjarne.fee() << '\n';
    }
    else
        cout << Bjarne.name() << " does not owe a fee\n";
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