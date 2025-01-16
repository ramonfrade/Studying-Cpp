#include <cmath>
#include <iomanip>
#include <iostream>

class Money
{
private:
    long int cents; // Amount in cents

    // Helper to round a double to the nearest cent
    long int roundToCents(double amount) const
    {
        return static_cast<long int>(std::round(amount * 100));
    }

public:
    // Constructors
    Money() : cents(0) {}

    Money(double dollars) : cents(roundToCents(dollars)) {}

    // Getters
    double getDollars() const
    {
        return cents / 100.0;
    }

    long int getCents() const
    {
        return cents;
    }

    // Arithmetic operations
    Money operator+(const Money& other) const
    {
        return Money((cents + other.cents) / 100.0);
    }

    Money operator-(const Money& other) const
    {
        return Money((cents - other.cents) / 100.0);
    }

    Money operator*(double factor) const
    {
        return Money((cents / 100.0) * factor);
    }

    Money operator/(double divisor) const
    {
        if(divisor == 0)
        {
            throw std::invalid_argument("Division by zero");
        }
        return Money((cents / 100.0) / divisor);
    }

    // Comparison operators
    bool operator==(const Money& other) const
    {
        return cents == other.cents;
    }

    bool operator!=(const Money& other) const
    {
        return cents != other.cents;
    }

    bool operator<(const Money& other) const
    {
        return cents < other.cents;
    }

    bool operator<=(const Money& other) const
    {
        return cents <= other.cents;
    }

    bool operator>(const Money& other) const
    {
        return cents > other.cents;
    }

    bool operator>=(const Money& other) const
    {
        return cents >= other.cents;
    }

    // Input and output
    friend std::ostream& operator<<(std::ostream& os, const Money& money)
    {
        os << "$" << std::fixed << std::setprecision(2) << money.getDollars();
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Money& money)
    {
        double dollars;
        is >> dollars;
        money.cents = money.roundToCents(dollars);
        return is;
    }
};

int main()
{
    Money m1(123.45), m2(76.55);

    std::cout << "Money 1: " << m1 << "\n";
    std::cout << "Money 2: " << m2 << "\n";

    Money sum = m1 + m2;
    std::cout << "Sum: " << sum << "\n";

    Money diff = m1 - m2;
    std::cout << "Difference: " << diff << "\n";

    Money product = m1 * 2.5;
    std::cout << "Product: " << product << "\n";

    Money quotient = m1 / 3.0;
    std::cout << "Quotient: " << quotient << "\n";

    return 0;
}
