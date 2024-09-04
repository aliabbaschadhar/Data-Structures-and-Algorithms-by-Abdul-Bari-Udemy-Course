#include <iostream>
#include <climits>

using namespace std;

// Function to print the array elements
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
void swap(int *a, int *b)
{
    // Use a temporary variable to hold one value while swapping
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Main bubble sort function
void BubbleSort(int funArray[], int size)
{
    int i, j, flag;

    // Outer loop runs through each pass of the bubble sort
    // Each pass compares adjacent elements and moves the largest unsorted element to the end
    for (i = 0; i < size; i++)
    {
        // Initialize flag to check if any swaps occurred in this pass
        // If no swaps occur in a pass, the array is already sorted
        flag = 0;

        // Inner loop compares adjacent elements and swaps if necessary
        // We compare up to size - i because the largest unsorted element moves to the end with each pass
        for (j = 0; j < size - i; j++)
        {
            // Compare current element with the next one
            // If current element is smaller than the next, swap them
            // This ensures that larger elements "bubble up" to the end of the unsorted portion
            if (funArray[j] < funArray[j + 1])
            {
                swap(&funArray[j], &funArray[j + 1]);
                flag = 1; // Set flag to indicate a swap occurred
            }
        }

        // If no swaps occurred in this pass, the array is already sorted
        // We can exit early because no further passes are needed
        if (flag == 0)
            break;
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

    // Perform bubble sort
    BubbleSort(testArray, size);

    // Print the sorted array
    cout << "Sorted array: ";
    printArray(testArray, size);

    return 0;
}