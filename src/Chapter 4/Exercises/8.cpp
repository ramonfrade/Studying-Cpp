#include "PPP2/std_lib_facilities.h"

int main()
{
    vector<int> desiredRices = {1000, 1000'000'000, 1'000'000'000};
    int squares = 1;
    int riceCurrentSquare = 1;
    int ricePreviousSquares = 0;
    int allGrains = 1;
    for(int i = 0; i < desiredRices.size(); i++)
    {
        while(desiredRices[i] > riceCurrentSquare + ricePreviousSquares)
        {
            cout << "Square: " << squares++ << '\n';
            cout << "\tGrains on current square: " << riceCurrentSquare << '\n';
            cout << "\tGrains on previous squares: " << ricePreviousSquares << '\n';
            cout << "\tTotal grains: " << allGrains << '\n';

            riceCurrentSquare *= 2;
            ricePreviousSquares = allGrains;
            allGrains += riceCurrentSquare;
        }
        cout << "The necessary amount of squares to give at least " << desiredRices[i]
             << " grains of rice is: " << squares << "!\n";
    }
    return 0;
}