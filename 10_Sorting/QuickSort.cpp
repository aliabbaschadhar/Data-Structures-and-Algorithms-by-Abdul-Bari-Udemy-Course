#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int *a, int *b)
{
    // Use a temporary variable to hold one value while swapping
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int partArray[], int low, int high)
{
    // Choose the first element as the pivot
    int pivot = partArray[low];
    int i = low + 1; // Start from the next element of the pivot
    int j = high;

    do
    {
        // Move i to the right until we find an element greater than or equal to the pivot
        do
        {
            i++;
        } while (i <= high && partArray[i] < pivot);

        // Move j to the left until we find an element less than or equal to the pivot
        do
        {
            j--;
        } while (j >= low && partArray[j] > pivot);

        // If i is still less than j, swap the elements at i and j
        if (i < j)
            swap(&partArray[i], &partArray[j]);

    } while (i < j);

    // Swap the pivot element with the element at j
    swap(&partArray[j], &partArray[low]);
    return j;
}

// Function to perform QuickSort
void QuickSort(int funcArray[], int low, int high)
{
    // Base case: If low is less than high, continue sorting
    if (low < high)
    {
        // Partition the array and get the pivot index
        int j = partition(funcArray, low, high);

        // Recursively sort the left and right subarrays
        QuickSort(funcArray, low, j - 1);  // Sort elements before the pivot
        QuickSort(funcArray, j + 1, high); // Sort elements after the pivot
    }
}

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    QuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}