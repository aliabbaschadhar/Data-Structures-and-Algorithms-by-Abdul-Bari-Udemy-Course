#include <iostream>
#include <climits>

using namespace std;

// Function to find the maximum element in the array
int findMax(int arr[], int n)
{
    // Initialize max with the smallest possible integer value
    int max = INT_MIN;

    // Iterate through the array to find the maximum element
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Return the maximum value found
    return max;
}

// Main counting sort function
void countSort(int Arr[], int n)
{
    // Find the maximum element in the array
    int max = findMax(Arr, n);

    // Create a count array to store counts of individual elements
    int *newArr = new int[max + 1];

    // Initialize all counts to zero
    for (int i = 0; i <= max; i++)
    {
        newArr[i] = 0;
    }

    // Count occurrences of each element
    for (int i = 0; i < n; i++)
    {
        newArr[Arr[i]]++;
    }

    // Build the sorted array
    int j = 0;
    for (int i = 0; i <= max; i++)
    {
        while (newArr[i] > 0)
        {
            Arr[j++] = i;
            newArr[i]--;
        }
    }

    // Deallocate memory for the count array
    delete[] newArr;
}

// Function to print the array
void printArray(int arr[], int n)
{
    // Print each element of the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Define the size of the array
    const int size = 10;

    // Create and initialize the test array
    int testArray[size] = {5, 2, 8, 1, 9, 3, 7, 6, 4, 0};

    // Print the original array
    cout << "Original array: ";
    printArray(testArray, size);

    // Perform counting sort
    countSort(testArray, size);

    // Print the sorted array
    cout << "Sorted array: ";
    printArray(testArray, size);

    return 0;
}