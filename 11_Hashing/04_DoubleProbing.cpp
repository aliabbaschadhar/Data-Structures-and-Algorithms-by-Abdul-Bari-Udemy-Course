#include <iostream>
#define SIZE 10 // Define the size of the hash table
#define PRIME 7 // Define a prime number for secondary hashing

using namespace std;

// Template function to print an array
template <class T>
void Print(T &vec, int n, string s)
{
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << flush;
        if (i < n - 1)
        {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

// Primary hash function to map a key to an index
int Hash(int key)
{
    // Use modulo operation to ensure the index is within the bounds of the table
    return key % SIZE;
}

// Secondary hash function using a prime number
int PrimeHash(int key)
{
    // Calculate the secondary hash using the prime number
    return PRIME - (key % PRIME);
}

// Double hashing function to handle collisions
int DoubleHash(int H[], int key)
{
    int idx = Hash(key); // Calculate the initial index using primary hash
    int i = 0;
    // Probe using double hashing until an empty slot is found
    while (H[(Hash(idx) + i * PrimeHash(key)) % SIZE] != 0)
    {
        i++;
    }
    // Return the index of the empty slot
    return (Hash(idx) + i * PrimeHash(key)) % SIZE;
}

// Insert a key into the hash table
void Insert(int H[], int key)
{
    int idx = Hash(key); // Calculate the initial index using primary hash

    // If the initial index is occupied, use double hashing to find an empty slot
    if (H[idx] != 0)
    {
        idx = DoubleHash(H, key);
    }
    // Insert the key into the hash table
    H[idx] = key;
}

// Search for a key in the hash table
int Search(int H[], int key)
{
    int idx = Hash(key); // Calculate the initial index using primary hash
    int i = 0;
    // Search using double hashing until the key is found or an empty slot is encountered
    while (H[(Hash(idx) + i * PrimeHash(key)) % SIZE] != key)
    {
        i++;
        // If an empty slot is found before finding the key, the key is not in the table
        if (H[(Hash(idx) + i * PrimeHash(key)) % SIZE] == 0)
        {
            return -1; // Return -1 to indicate the key is not found
        }
    }
    // Return the index where the key is found
    return (Hash(idx) + i * PrimeHash(key)) % SIZE;
}

int main()
{
    // Array of keys to insert into the hash table
    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A) / sizeof(A[0]); // Calculate the number of elements in A

    // Print the array A
    Print(A, n, "A");

    // Initialize the hash table with zeros
    int HT[SIZE] = {0};

    // Insert keys from array A into the hash table
    for (int i = 0; i < n; i++)
    {
        Insert(HT, A[i]);
    }

    // Print the hash table
    Print(HT, SIZE, "HT");

    // Search for a key in the hash table
    int index = Search(HT, 25);
    cout << "Key found at: " << index << endl;

    // Search for another key in the hash table
    index = Search(HT, 35);
    cout << "Key found at: " << index << endl;

    return 0;
}