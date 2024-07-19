#include "ppp2/std_lib_facilities.h"

int main()
{
    vector<int> desiredRices{1000, 1'000'000, 1'000'000'000};
    int square = 1;
    int riceCurrentSquare = 1;
    int ricePreviousSquares = 0;
    int totalRice = 0;

    for(int i = 0; i < desiredRices.size(); i++)
    {
        while(desiredRices[i] >= riceCurrentSquare + ricePreviousSquares)
        {
            cout << "Square: " << square++ << '\n';
            cout << "\tGrains on current square: " << riceCurrentSquare << '\n';
            cout << "\tGrains on previous squares: " << ricePreviousSquares << '\n';
            cout << "\tTotal rice: " << totalRice << '\n';
            riceCurrentSquare *= 2;
            ricePreviousSquares = totalRice;
            totalRice += riceCurrentSquare;
        }
        cout << "It was necessary " << square << " squares to give at least " << desiredRices[i] << '\n';
    }
    return 0;
}
