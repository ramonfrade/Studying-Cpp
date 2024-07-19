#include "ppp2/std_lib_facilities.h"

int main()
{
    vector<int> prime_numbers{2};
    int max = 0;
    cout << "Give me a value and I will check how many prime numbers have from 1 to this number\n";
    cin >> max;

    for(int x = 3; x <= max; x++)
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
    cout << "All the prime numbers beetween 1 and " << max << " are: ";
    for(int y = 0; y < prime_numbers.size(); y++) { cout << prime_numbers[y] << " "; }
}
