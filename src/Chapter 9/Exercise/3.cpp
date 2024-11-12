#include "ppp2/std_lib_facilities.h"

class Name_pairs
{
    vector<string> name;
    vector<double> age;

public:
    void read_names(); //reads a series of names
    void read_ages();  //prompts the user for an age for each name
    void sort();       //sort name vector in alphabetical order

    const vector<string>& get_name() const
    {
        return name;
    }

    const vector<double>& get_age() const
    {
        return age;
    }
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

ostream& operator<<(ostream& os, const Name_pairs& n)
{
    if(n.get_name().size() != n.get_age().size())
    {
        error("<<: name and age sizes must be equal");
    }

    for(int i = 0; i < n.get_name().size(); i++) { os << '(' << n.get_name()[i] << ", " << n.get_age()[i] << ")\n"; }
    return os;
}
int main()
try
{
    Name_pairs nomes;
    nomes.read_names();
    nomes.read_ages();
    cout << "Names and ages pre sort: \n";
    cout << nomes;
    nomes.sort();
    cout << "Names and ages after sort: \n";
    cout << nomes;
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