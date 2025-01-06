#include "ppp2/std_lib_facilities.h"

class Rational
{
public:
    //Default constructor
    Rational(int numerator, int denominator) : numerator_{numerator}, denominator_{denominator} {};

    int Numerator() const
    {
        return numerator_;
    }

    int Denominator() const
    {
        return denominator_;
    }

private:
    int numerator_;
    int denominator_ = 1;
};

Rational operator+(const Rational& left, const Rational& right)
{
    if(left.Denominator() == right.Denominator())
    {
        return Rational(left.Numerator() + right.Numerator(), left.Denominator());
    }
    else
    {
        //Getting the least common multiple
        int new_denominator = left.Denominator() * right.Denominator();
        //Numbers after the least common multiple
        Rational new_left(new_denominator / left.Denominator() * left.Numerator(), new_denominator);
        Rational new_right(new_denominator / right.Denominator() * right.Numerator(), new_denominator);
        return Rational(new_left.Numerator() + new_right.Numerator(), new_denominator);
    }
}

Rational operator-(const Rational& left, const Rational& right)
{
    if(left.Denominator() == right.Denominator())
    {
        return Rational(left.Numerator() - right.Numerator(), left.Denominator());
    }
    else
    {
        //Getting the least common multiple
        int new_denominator = left.Denominator() * right.Denominator();
        //Numbers after the least common multiple
        Rational new_left(new_denominator / left.Denominator() * left.Numerator(), new_denominator);
        Rational new_right(new_denominator / right.Denominator() * right.Numerator(), new_denominator);
        return Rational(new_left.Numerator() - new_right.Numerator(), new_denominator);
    }
}

Rational operator*(const Rational& left, const Rational& right)
{
    return Rational(left.Numerator() * right.Numerator(), left.Denominator() * right.Denominator());
}

Rational operator/(const Rational& left, const Rational& right)
{
    return Rational(left.Numerator() * right.Denominator(), left.Denominator() * right.Numerator());
}

bool operator==(const Rational& left, const Rational& right)
{
    return left.Numerator() == right.Numerator() && left.Denominator() == right.Denominator();
}