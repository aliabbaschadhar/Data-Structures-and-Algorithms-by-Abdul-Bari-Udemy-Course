#include <iostream>

using namespace std;

// Function to merge two sorted subarrays
void MergeTwo(int A[], int B[], int m, int n)
{
    int C[100];
    int i, j, k;
    i = j = k = 0;

    // Merge smaller elements first
    while (i < m && j < n)
    {
        if (A[i] <= B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }

    // Copy remaining elements of A[], if any
    while (i < m)
    {
        C[k++] = A[i++];
    }

    // Copy remaining elements of B[], if any
    while (j < n)
    {
        C[k++] = B[j++];
    }

    // Copy the merged array C[] back to A[]
    for (int i = 0; i < m + n; i++)
    {
        A[i] = C[i];
    }
}

// Function to perform merge sort on a single subarray
void MergeSingle(int arr[], int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

    // Create a temporary array to store the merged result
    int arr2[high + 1];

    // Compare elements from left and right halves and copy smaller ones to arr2
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            arr2[k++] = arr[i++];
        }
        else
        {
            arr2[k++] = arr[j++];
        }
    }

    // Copy remaining elements from left half, if any
    for (; i <= mid; i++)
    {
        arr2[k++] = arr[i];
    }

    // Copy remaining elements from right half, if any
    for (; j <= high; j++)
    {
        arr2[k++] = arr[j];
    }

    // Copy the sorted elements back to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = arr2[i];
    }
}

// Main function to perform merge sort
void MergeSort(int array[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        // Recursively sort left half
        MergeSort(array, low, mid);

        // Recursively sort right half
        MergeSort(array, mid + 1, high);

        // Merge the sorted left and right halves
        MergeSingle(array, low, mid, high);
    }
}

int main()
{
    int m = 4;
    int n = 4;
    int arr[m] = {2, 4, 5, 6};
    int arr2[n] = {3, 8, 9, 10};

    // Perform merge sort on arr[]
    MergeSort(arr, 0, m - 1);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < m; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}