#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

string Generate_Password(int Length)
{

    const string charSetOfPass = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    const int charLength = charSetOfPass.length();
    string Password;

    srand(time(0));

    for (int x = 0; x < Length; x++)
    {
        int RandomIndex = rand() % charLength;
        Password += charSetOfPass[RandomIndex];
    }
    return Password;
}


int main()
{
    int length;

    cout << "Enter The length of password you want to set : ";
    cin >> length;
    if (length > 0)
    {
        string password = Generate_Password(length);
        cout << "Generated Password: " << password << endl;
        return 1;
    }
    else
    {
        cout << "Invalid password length. Please enter a positive integer." << endl;
        return 1;
    }
}
