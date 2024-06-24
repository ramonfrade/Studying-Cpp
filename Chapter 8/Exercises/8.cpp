#include "../../../std_lib_facilities.h"

vector<string> new_vec(const vector<string> &v)
{
    vector<string> new_vec;
    for (int i = 0; i < v.size(); i++)
    {
        new_vec.push_back(v[i]);
    }
    return new_vec;
}

void print(const vector<string> &name, const vector<double> &age)
{
    cout << "Names and ages pairs: \n";
    for (int i = 0; i < name.size(); i++)
    {
        cout << name[i] << ", " << age[i] << '\n';
    }
}

void swap(double &a, double &b)
{
    double temp;
    temp = a;
    a = b;
    b = temp;
}

void sort_age(const vector<string> &name, const vector<string> copy_name, const vector<double> &age, vector<double> &sorted_age)
{
    int x = 0;
    for (string s : name)
    {
        for (int i = 0; i < name.size(); i++)
        {
            if (s == copy_name[i])
            {
                sorted_age.push_back(age[i]);
            }
        }
    }
}

int main()
{
    vector<string> name;
    vector<double> age;
    cout << "Enter names of people: (type '|' to stop)\n";
    string names;
    while (cin >> names)
    {
        if (names == "|")
        {
            break;
        }
        name.push_back(names);
    }

    for (string s : name)
    {
        cout << "How old is: " << s << "?\n";
        int ages;
        cin >> ages;
        age.push_back(ages);
    }
    
    print(name, age);
    vector<string> copy_name = new_vec(name);
    vector<double> sorted_age;
    sort(name.begin(), name.end());
    sort_age(name, copy_name, age, sorted_age);
    print(name, sorted_age);
}