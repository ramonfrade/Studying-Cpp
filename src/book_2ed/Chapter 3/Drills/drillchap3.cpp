#include "ppp2/std_lib_facilities.h"

int main()
{
    cout << "Enter the name of the person you want to write to:\n";
    string first_name;
    cin >> first_name;
    string friend_name;
    cout << "Enter the name of a mutual friend:\n";
    cin >> friend_name;
    char friend_sex = 0;
    cout << "Enter an 'm' if the friend is male and an 'f' if the friend is female:\n";
    cin >> friend_sex;
    cout << "Enter the recipient age:\n";
    int age = 0;
    cin >> age;
    if(age <= 0 or age >= 110)
        simple_error("you're kidding!");
    cout << "Dear " << first_name << ",\n"
         << "How are you? I am fine. I miss you.\n"
         << "Have you seen " << friend_name << " lately?\n";
    if(friend_sex == 'm')
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    if(friend_sex == 'f')
        cout << "If you see " << friend_name << " please ask her to call me.\n";
    cout << "I hear you just had a birthday and you are " << age << " years old.\n";
    if(age <= 12)
        cout << "Next year you will be " << age + 1 << ".\n";
    else if(age == 17)
        cout << "Next year you will be able to vote.\n";
    else if(age >= 70)
        cout << "I hope you are enjoying retirement.\n";
    cout << "Yours sincerely,\n\nRamon Frade.\n";
}
