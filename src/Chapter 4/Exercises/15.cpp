#include "PPP2/std_lib_facilities.h"

int main()
{
    cout << "Enter an integer: \n";
    int n = 0;
    cin >> n;

    vector<int> primes{2};

    for(int x = 3; primes.size() < n; x++)
    {
        bool is_prime = true;
        for(int i = 0; i < primes.size(); i++)
        {
            if(x % primes[i] == 0)
            {
                is_prime = false;
                break;
            }
        }
        if(is_prime == true)
        {
            primes.push_back(x);
        }
    }
    cout << "The first " << n << " prime numbers are: ";
    for(int i = 0; i < primes.size(); i++) { cout << primes[i] << " "; }
}
