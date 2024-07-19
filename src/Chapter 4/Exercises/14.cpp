#include "ppp2/std_lib_facilities.h"

int main()
{
    vector<int> integers{};
    vector<int> primes{};

    cout << "Give me a value and I will check how many prime numbers have from 1 to this number\n";
    int max = 0;
    cin >> max;

    for(int i = 2; i <= max; i++) { integers.push_back(i); }
    for(int i = 0; i < integers.size(); i++)
    {
        if(integers[i] == 2 || integers[i] == 3 || integers[i] == 5 || integers[i] == 7
           || integers[i] % 2 != 0 && integers[i] % 3 != 0 && integers[i] % 5 != 0 && integers[i] % 7 != 0)
        {
            primes.push_back(integers[i]);
        }
    }
    cout << "All the prime numbers beetween 1 and " << max << " are: ";
    for(int i = 0; i < primes.size(); i++) { cout << primes[i] << " "; }
}
