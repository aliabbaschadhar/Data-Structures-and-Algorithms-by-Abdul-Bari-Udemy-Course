#include <iostream>
using namespace std;

// Function to check if a string is valid
bool checkValidation(string name)
{
    // Check if the string contains only letters and digits
    for (int i = 0; i < name.length(); i++)
    {
        if (!(name[i] >= 'A' && name[i] <= 'Z') && !(name[i] >= 'a' && name[i] <= 'z') && !(name[i] >= '0' && name[i] <= '9'))
        {
            return false; // Return false if the string is not valid
        }
    }
    return true; // Return true if the string is valid
}

int main()
{
    string name = "aliabbas%";
    if (checkValidation(name))
    {
        cout << "Valid String"; // Print "Valid String" if the string is valid
    }
    else
    {
        cout << "Not Valid String"; // Print "Not Valid String" if the string is not valid
    }
    return 0;
}