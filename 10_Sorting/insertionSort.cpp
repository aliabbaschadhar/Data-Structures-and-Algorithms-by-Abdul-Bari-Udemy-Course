#include <iostream>

using namespace std;

// Function to print the array
void printArray(int arr[], int n)
{
    // Iterate through the array and print each element
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to swap two elements
void swap(int *val1, int *val2)
{
    // Use a temporary variable to hold one value while swapping
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

// Main insertion sort function
void InsertionSort(int funcArray[], int size)
{
    // Start from the second element (index 1) since the first element is already sorted
    for (int i = 1; i < size; i++)
    {
        // Store the current element to be inserted
        int j = i - 1;
        int value = funcArray[i];

        // Compare the stored element with sorted portion and shift if needed
        while (funcArray[j] > value)
        {
            // Shift the greater element to the right
            funcArray[j + 1] = funcArray[j];
            j--;
        }

        // Insert the stored element at its correct position
        funcArray[j + 1] = value;
    }
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

    // Perform insertion sort
    InsertionSort(testArray, size);

    // Print the sorted array
    cout << "Sorted array: ";
    printArray(testArray, size);

    return 0;
}
