#include <iostream>
#include <map>

using namespace std;

int main()
{
    // Create a map to store integer keys and string values
    map<int, string> m;

    // Insert key-value pairs into the map
    m.insert(pair<int, string>(1, "ali "));
    m.insert(pair<int, string>(2, "saba "));
    m.insert(pair<int, string>(3, "baby "));

    // Create an iterator to traverse the map
    map<int, string>::iterator itr;

    // Iterate through the map and print all key-value pairs
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
    cout << endl;

    // Create another iterator to find a specific key in the map
    map<int, string>::iterator itr1;
    itr1 = m.find(2); // Find the element with key 2

    // Print the found key-value pair
    cout << itr1->first;         // Print the key
    cout << " " << itr1->second; // Print the value

    return 0;
}
