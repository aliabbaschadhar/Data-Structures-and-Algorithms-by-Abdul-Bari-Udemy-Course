#include <iostream>
using namespace std;

int main()
{
    char str[] = "finding";
    int H[26] = {0}; // Initialize the array to 0
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        H[str[i] - 'a']++; // Increment the count of the character
    }
    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            cout << (char)(i + 'a');                 // Print the character
            cout << " " << H[i] << " Times" << endl; // Print the count
        }
    }
    return 0;
}
