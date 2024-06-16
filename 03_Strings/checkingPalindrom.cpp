
#include <iostream>
using namespace std;

bool CheckPalindrom(char palindrom[])
{
    int i, j;
    // Calculate the length of the string
    for (i = 0; palindrom[i] != '\0'; i++)
    {
    }
    j = i - 1;

    // Check if the string is a palindrome
    for (i = 0; j > i; i++, j--)
    {
        if (palindrom[i] != palindrom[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char palindrom[] = "ghfd";
    if (CheckPalindrom(palindrom))
    {
        cout << "PALINDROME";
    }
    else
    {
        cout << "NOT PALINDROME";
    }
    return 0;
}
