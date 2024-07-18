#include "PPP2/std_lib_facilities.h"

int main()
{
    vector<int> numbers;
    int mode = 0;
    int reps = 1;
    int max_reps = 1;
    cout << "Enter positive integers: (Type '|' to stop)\n";
    for(int input; cin >> input;) { numbers.push_back(input); }

    sort(numbers);

    for(int i = 1; i < numbers.size(); i++)
    {
        if(numbers[i] == numbers[i - 1])
        {
            reps++;
        }
        else
        {
            reps = 1;
        }
        if(max_reps < reps)
        {
            mode = numbers[i];
            max_reps = reps;
        }
    }

    cout << "The mode of the series is " << mode << " with " << max_reps << " repetitions.\n";
}