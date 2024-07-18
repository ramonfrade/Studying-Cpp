#include "PPP2/std_lib_facilities.h"

int main()
{
    vector<double> distances{};
    double median = 0;
    double first_num = 0;
    double second_num = 20;
    double sum = 0;
    for(double distance; cin >> distance;)
    {
        sum += distance;
        distances.push_back(distance);
        sort(distances);
        cout << "The sum of all distances are: " << sum << '\n';
        cout << "The smallest distance between two neighboring cities is: " << distances[0] << '\n';
        cout << "The greatest distance between two neighboring cities is: " << distances[distances.size() - 1] << '\n';
        cout << "The mean distance between two neighboring cities is: " << sum / distances.size() << '\n';
    }
}