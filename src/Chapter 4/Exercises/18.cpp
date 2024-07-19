#include "ppp2/std_lib_facilities.h"

int main()
{

    cout << "Enter the values of a, b and c of a quadratic equation:\n";

    double a;
    double b;
    double c;
    double x1;
    double x2;

    cin >> a >> b >> c;

    x1 = (-b + sqrt((b * b) - 4 * a * c)) / (2 * a);
    x2 = (-b - sqrt((b * b) - 4 * a * c)) / (2 * a);

    cout << x1 << " and " << x2 << " are the roots.\n";
}
