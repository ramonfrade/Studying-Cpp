#include "ppp2/std_lib_facilities.h"

int main()
{
    vector<int> prime_numbers{2};

    for(int x = 3; x < 101; x++)
    {
        bool is_prime = true;
        for(int i = 0; i < prime_numbers.size(); i++)
        {
            if(x % prime_numbers[i] == 0)
            {
                is_prime = false;
                break;
            }
        }
        if(is_prime == true)
        {
            prime_numbers.push_back(x);
        }
    }
    cout << "All the prime numbers beetween 1 and 100 are: ";
    for(int y = 0; y < prime_numbers.size(); y++) { cout << prime_numbers[y] << " "; }
}
