#include <iostream>

using namespace std;

// Function to perform selection sort
void SelectionSort(int arr[], int n)
{
    // Iterate through each element in the array
    for (int i = 0; i < n - 1; i++)
    {
        // Initialize minimum index to the current element
        int minIndex = i;

        // Find the smallest element in the unsorted portion of the array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted portion
        swap(arr[i], arr[minIndex]);
    }
}

// Function to print the array elements
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
    int n;

    // Prompt user to enter the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Create an array of the specified size
    int arr[n];

    // Prompt user to input elements of the array
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Print the original array
    cout << "Original values are : ";
    printArray(arr, n);

    // Perform selection sort
    SelectionSort(arr, n);

    // Print the sorted array
    cout << "Sorted values are : ";
    printArray(arr, n);

    return 0;
}