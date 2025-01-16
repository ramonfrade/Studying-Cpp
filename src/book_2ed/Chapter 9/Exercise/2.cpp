#include "ppp2/std_lib_facilities.h"

class Name_pairs
{
    vector<string> name;
    vector<double> age;

public:
    void read_names(); //reads a series of names
    void read_ages();  //prompts the user for an age for each name

    void print() const; //prints name[i], age[i] pairs
    void sort();        //sort name vector in alphabetical order
};

void Name_pairs::read_names()
{
    string n;
    cout << "Enter names, type '|' to stop: ";
    while(cin >> n && n != "|")
    {
        for(int i = 0; i < name.size(); i++)
        {
            if(name[i] == n)
            {
                error("read_names(): name already exists: ", n);
            }
        }
        name.push_back(n);
    }
}

void Name_pairs::read_ages()
{
    double a;
    for(int i = 0; i < name.size(); i++)
    {
        cout << "Enter the age of " << name[i] << ": ";
        cin >> a;
        age.push_back(a);
    }
}

void Name_pairs::print() const
{
    if(name.size() != age.size())
    {
        error("print(): name and age must be the same size");
    }
    for(int i = 0; i < name.size(); i++) { cout << '(' << name[i] << ", " << age[i] << ")\n"; }
}

void Name_pairs::sort()
{
    if(name.size() != age.size())
    {
        error("sort(): name and age must be the same size");
    }

    vector<string> name_presort = name;
    vector<double> age_presort = age;
    std::sort(name.begin(), name.end());
    for(int i = 0; i < name.size(); i++)
    {
        for(int j = 0; j < name_presort.size(); j++)
        {
            if(name[i] == name_presort[j])
            {
                age[i] = age_presort[j];
            }
        }
    }
}

int main()
try
{
    Name_pairs nomes;
    nomes.read_names();
    nomes.read_ages();
    cout << "Names and ages pre sort: \n";
    nomes.print();
    nomes.sort();
    cout << "Names and ages after sort: \n";
    nomes.print();
}
catch(exception& e)
{
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch(...)
{
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}