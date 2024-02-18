#include "../../../std_lib_facilities.h"

int main(){

    int squares = 1;
    const int last_square = 64;
    int current_rice = 1;
    int total_rice = 1;
    double CurrentRice = 1;
    double TotalRice = 1;

    while (squares <= last_square)
    {
        cout << "Square " << squares++ << ": " << current_rice << " grains of rice.\n";
        cout << "\t Total rice: " << total_rice << '\n';
        current_rice *= 2;
        total_rice += current_rice;
    }
    
}