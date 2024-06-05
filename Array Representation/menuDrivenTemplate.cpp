#include <iostream>
using namespace std;

// Template class for an array
template <class T>
class Array
{
private:
    T *A;                  // Array of type T
    int size;              // Size of the array
    int length;            // Current length of the array
    void swap(T *x, T *y); // Function to swap two elements

public:
    // Constructor to initialize the array
    Array()
    {
        size = 10;       // Default size of the array
        length = 0;      // Initialize length to 0
        A = new T[size]; // Allocate memory for the array
    }

    // Constructor to initialize the array with a given size
    Array(int sz)
    {
        size = sz;       // Set the size of the array
        length = 0;      // Initialize length to 0
        A = new T[size]; // Allocate memory for the array
    }

    // Destructor to deallocate memory
    ~Array()
    {
        delete[] A; // Deallocate memory
    }

    // Function to display the array
    void Display()
    {
        int i;
        cout << "\nElements are\n";
        for (i = 0; i < length; i++)
            cout << A[i] << " ";
    }

    // Function to append an element to the array
    void Append(T x)
    {
        if (length < size)   // Check if the array is not full
            A[length++] = x; // Append the element
    }

    // Function to insert an element at a given index
    void Insert(int index, T x)
    {
        int i;
        if (index >= 0 && index <= length)
        {
            for (i = length; i > index; i--)
                A[i] = A[i - 1]; // Shift elements to make space
            A[index] = x;        // Insert the element
            length++;            // Increment length
        }
    }

    // Function to delete an element at a given index
    T Delete(int index)
    {
        T x = 0;
        int i;

        if (index >= 0 && index < length)
        {
            x = A[index]; // Store the element to be deleted
            for (i = index; i < length - 1; i++)
                A[i] = A[i + 1]; // Shift elements to fill the gap
            length--;            // Decrement length
            return x;            // Return the deleted element
        }

        return 0;
    }

    // Function to swap two elements
    void swap(T *x, T *y)
    {
        T temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

    // Function to perform linear search
    int LinearSearch(T key)
    {
        int i;
        for (i = 0; i < length; i++)
        {
            if (key == A[i])
                return i; // Return the index if found
        }
        return -1; // Return -1 if not found
    }

    // Function to perform binary search
    int BinarySearch(T key)
    {
        int l, mid, h;
        l = 0;
        h = length - 1;

        while (l <= h)
        {
            mid = (l + h) / 2;
            if (key == A[mid])
                return mid; // Return the index if found
            else if (key < A[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1; // Return -1 if not found
    }

    // Function to get an element at a given index
    T Get(int index)
    {
        if (index >= 0 && index < length)
            return A[index]; // Return the element
        return -1;           // Return -1 if out of bounds
    }

    // Function to set an element at a given index
    void Set(int index, T x)
    {
        if (index >= 0 && index < length)
            A[index] = x; // Set the element
    }

    // Function to find the maximum element
    T Max()
    {
        T max = A[0];
        int i;
        for (i = 1; i < length; i++)
        {
            if (A[i] > max)
                max = A[i]; // Update the maximum
        }
        return max;
    }

    // Function to find the minimum element
    T Min()
    {
        T min = A[0];
        int i;
        for (i = 1; i < length; i++)
        {
            if (A[i] < min)
                min = A[i]; // Update the minimum
        }
        return min;
    }

    // Function to calculate the sum of elements
    T Sum()
    {
        T s = 0;
        int i;
        for (i = 0; i < length; i++)
            s += A[i]; // Calculate the sum
        return s;
    }

    // Function to calculate the average of elements
    float Avg()
    {
        return (float)Sum() / length; // Calculate the average
    }

    // Function to reverse the array
    void Reverse()
    {
        T *B;
        int i, j;

        B = new T[length];
        for (i = length - 1, j = 0; i >= 0; i--, j++)
            B[j] = A[i]; // Copy elements to a temporary array
        for (i = 0; i < length; i++)
            A[i] = B[i]; // Copy back to the original array
        delete[] B;      // Deallocate memory
    }

    // Function to reverse the array in place
    void Reverse2()
    {
        int i, j;
        for (i = 0, j = length - 1; i < j; i++, j--)
            swap(&A[i], &A[j]); // Swap elements
    }

    // Function to insert an element in sorted order
    void InsertSort(T x)
    {
        int i = length - 1;
        if (length == size)
            return; // Return if the array is full
        while (i >= 0 && A[i] > x)
        {
            A[i + 1] = A[i]; // Shift elements to make space
            i--;
        }
        A[i + 1] = x; // Insert the element
        length++;     // Increment length
    }

    // Function to check if the array is sorted
    int isSorted()
    {
        int i;
        for (i = 0; i < length - 1; i++)
        {
            if (A[i] > A[i + 1])
                return 0; // Return 0 if not sorted
        }
        return 1; // Return 1 if sorted
    }

    // Function to rearrange the array
    void Rearrange()
    {
        int i, j;
        i = 0;
        j = length - 1;

        while (i < j)
        {
            while (A[i] < 0)
                i++;
            while (A[j] >= 0)
                j--;
            if (i < j)
                swap(&A[i], &A[j]); // Swap elements
        }
    }

    // Function to merge two arrays
    Array<T> *Merge(Array<T> &arr2)
    {
        int i, j, k;
        i = j = k = 0;

        Array<T> *arr3 = new Array<T>(length + arr2.length);

        while (i < length && j < arr2.length)
        {
            if (A[i] < arr2.A[j])
                arr3->A[k++] = A[i++];
            else
                arr3->A[k++] = arr2.A[j++];
        }
        for (; i < length; i++)
            arr3->A[k++] = A[i];
        for (; j < arr2.length; j++)
            arr3->A[k++] = arr2.A[j];
        arr3->length = k;

        return arr3;
    }

    // Function to find the union of two arrays
    Array<T> *Union(Array<T> &arr2)
    {
        int i, j, k;
        i = j = k = 0;

        Array<T> *arr3 = new Array<T>(length + arr2.length);

        while (i < length && j < arr2.length)
        {
            if (A[i] < arr2.A[j])
                arr3->A[k++] = A[i++];
            else if (arr2.A[j] < A[i])
                arr3->A[k++] = arr2.A[j++];
            else
            {
                arr3->A[k++] = A[i++];
                j++;
            }
        }
        for (; i < length; i++)
            arr3->A[k++] = A[i];
        for (; j < arr2.length; j++)
            arr3->A[k++] = arr2.A[j];
        arr3->length = k;

        return arr3;
    }

    // Function to find the intersection of two arrays
    Array<T> *Inter(Array<T> &arr2)
    {
        int i, j, k;
        i = j = k = 0;

        Array<T> *arr3 = new Array<T>(length + arr2.length);

        while (i < length && j < arr2.length)
        {
            if (A[i] < arr2.A[j])
                i++;
            else if (arr2.A[j] < A[i])
                j++;
            else
            {
                arr3->A[k++] = A[i++];
                j++;
            }
        }

        arr3->length = k;

        return arr3;
    }

    // Function to find the difference of two arrays
    Array<T> *Diff(Array<T> &arr2)
    {
        int i, j, k;
        i = j = k = 0;

        Array<T> *arr3 = new Array<T>(length + arr2.length);

        while (i < length && j < arr2.length)
        {
            if (A[i] < arr2.A[j])
                arr3->A[k++] = A[i++];
            else if (arr2.A[j] < A[i])
                j++;
            else
            {
                i++;
                j++;
            }
        }
        for (; i < length; i++)
            arr3->A[k++] = A[i];

        arr3->length = k;

        return arr3;
    }
};

int main()
{
    Array<int> *arr1;
    int ch, sz;
    int x, index;

    cout << "Enter Size of Array: ";
    cin >> sz;
    arr1 = new Array<int>(sz);

    do
    {
        cout << "\n\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter an element and index: ";
            cin >> x >> index;
            arr1->Insert(index, x);
            break;
        case 2:
            cout << "Enter index: ";
            cin >> index;
            x = arr1->Delete(index);
            cout << "Deleted Element is " << x;
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> x;
            index = arr1->LinearSearch(x);
            cout << "Element index " << index;
            break;
        case 4:
            cout << "Sum is " << arr1->Sum();
            break;
        case 5:
            arr1->Display();
            break;
        }
    } while (ch < 6);
    return 0;
}