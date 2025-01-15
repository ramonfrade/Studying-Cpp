#include "ppp2/std_lib_facilities.h"

class Money
{
public:
    Money(string currency, double dollars);

    long int getCents() const
    {
        return cents;
    }

    double getDollars() const
    {
        return cents / 100.0;
    }

    double getBRL() const
    {
        return cents / 100 / 0.16;
    }

    double getDKK() const
    {
        return cents / 100 / 0.14;
    }

private:
    long int cents;
};

Money::Money(string currency, double dollars)
{
    if(currency == "BRL")
    {
        cents = dollars * 0.16 * 100;
    }
    else if(currency == "DKK")
    {
        cents = dollars * 0.14 * 100;
    }
    else
        cents = dollars * 100;
}

Money operator+(const Money& left, const Money& right)
{
    return Money("USD", (left.getCents() + right.getCents()) / 100);
}

Money operator-(const Money& left, const Money& right)
{
    return Money("USD", (left.getCents() - right.getCents()) / 100);
}

Money operator*(const Money& left, const double& factor)
{
    double result = (left.getCents() * factor) / 100;
    if(result - int(result) >= 0.5)
        return Money("USD", result + 0.01);
    else
        return Money("USD", result);
}

Money operator/(const Money& left, const double& divisor)
{
    if(divisor == 0)
    {
        error("operator/: division by 0");
    }
    double result = (left.getCents() / divisor) / 100;
    if(result - int(result) >= 0.5)
        return Money("USD", result + 0.01);
    else
        return Money("USD", result);
}

istream& operator>>(istream& is, Money& money)
{
    string input;
    cin >> input;
    istringstream iss(input);
    string currency;
    double value;
    while(iss.peek() < '0' || iss.peek() > '9') { currency += iss.get(); }
    iss >> value;

    money = Money(currency, value);
    return is;
}

int main()
try
{
    Money test("USD", 0);
    cin >> test;
    cout << "test USD: $" << test.getDollars() << " (" << test.getCents() << " cents)" << endl;

    // Testing constructors and getter methods
    Money usd("USD", 100.0);
    cout << "USD: $" << usd.getDollars() << " (" << usd.getCents() << " cents)" << endl;

    Money brl("BRL", 100.0);
    cout << "BRL: $" << brl.getDollars() << " (" << brl.getCents() << " cents)" << endl;

    Money dkk("DKK", 100.0);
    cout << "DKK: $" << dkk.getDollars() << " (" << dkk.getCents() << " cents)" << endl;

    // Testing addition
    Money sum = usd + brl;
    cout << "USD + BRL: $" << sum.getDollars() << " (" << sum.getCents() << " cents)" << endl;

    // Testing subtraction
    Money diff = usd - dkk;
    cout << "USD - DKK: $" << diff.getDollars() << " (" << diff.getCents() << " cents)" << endl;

    // Testing multiplication
    Money product = usd * 1.5;
    cout << "USD * 1.5: $" << product.getDollars() << " (" << product.getCents() << " cents)" << endl;

    // Testing division
    Money quotient = usd / 2;
    cout << "USD / 2: $" << quotient.getDollars() << " (" << quotient.getCents() << " cents)" << endl;

    return 0;
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