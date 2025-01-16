#include "ppp2/std_lib_facilities.h"

class Money
{
public:
    Money(double dollars) : cents{dollars * 100} {};

    long int getCents() const
    {
        return cents;
    }

    double getDollars() const
    {
        return cents / 100.0;
    }

private:
    long int cents;
};

Money operator+(const Money& left, const Money& right)
{
    return (left.getCents() + right.getCents()) / 100;
}

Money operator-(const Money& left, const Money& right)
{
    return (left.getCents() - right.getCents()) / 100;
}

Money operator*(const Money& left, const double& factor)
{
    double result = (left.getCents() * factor) / 100;
    if(result - int(result) >= 0.5)
        return result + 0.01;
    else
        return result;
}

Money operator/(const Money& left, const double& divisor)
{
    if(divisor == 0)
    {
        error("operator/: division by 0");
    }
    double result = (left.getCents() / divisor) / 100;
    if(result - int(result) >= 0.5)
        return result + 0.01;
    else
        return result;
}

int main()
{
    Money m1(123.45), m2(76.55);

    cout << "Money 1: " << m1.getDollars() << "\n";
    cout << "Money 2: " << m2.getDollars() << "\n";

    Money sum = m1 + m2;
    cout << "Sum: " << sum.getDollars() << "\n";

    Money diff = m1 - m2;
    cout << "Difference: " << diff.getDollars() << "\n";

    Money product = m1 * 2.5;
    cout << "Product: " << product.getDollars() << "\n";

    Money quotient = m1 / 3.0;
    cout << "Quotient: " << quotient.getDollars() << "\n";

    return 0;
}