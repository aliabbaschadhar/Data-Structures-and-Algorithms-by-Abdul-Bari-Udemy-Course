#include <iostream>
#include <climits>

using namespace std;

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Shell Sort

void ShellSort(int funcArray[], int size)
{
    int i, j, gap;

    // for(gap=size/2); gap<=1; gap/=2)
    // For gap passes gap=14/2,7/2,3/2,1
    for (gap = size / 2; gap >= 1; gap /= 2)
    {
        // For moving gap forward
        for (i = gap; i < size; i++)
        {
            // Almost insertion sort in shell sort way
            j = i - gap;
            int value = funcArray[i]; // copied value
            while (j >= 0 && funcArray[j] > value)
            {
                funcArray[j + gap] = funcArray[j];
                j = j - gap;
            }
            funcArray[j + gap] = value;
        }
    }
}

int main()
{
    const int size = 10;
    int testArray[size] = {5, 2, 8, 1, 9, 3, 7, 6, 4, 0};

    cout << "Original array: ";
    printArray(testArray, size);

    ShellSort(testArray, size);

    cout << "Sorted array: ";
    printArray(testArray, size);
    return 0;
}