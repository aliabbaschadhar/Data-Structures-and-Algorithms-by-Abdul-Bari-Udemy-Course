#include <iostream>
using namespace std;

// Class to represent an element in a sparse matrix
class Element
{
public:
    int row;    // Row index
    int colomn; // Column index
    int value;  // Value of the element
};

// Class to represent a sparse matrix
class Sparse
{
private:
    // Dimensions
    int m;        // Number of rows
    int n;        // Number of columns
    int num;      // Number of non-zero elements
    Element *ele; // Array of elements

public:
    // Constructor to initialize the sparse matrix
    Sparse(int m, int n, int num) : m(m), n(n), num(num)
    {
        ele = new Element[num]; // Create array of i, j, x
    }

    // Destructor to deallocate memory
    ~Sparse()
    {
        delete[] ele;
    }

    // Method to create the sparse matrix
    void create()
    {
        cout << "Enter non-zero elements:\n";
        for (int i = 0; i < num; i++)
        {
            cin >> ele[i].row >> ele[i].colomn >> ele[i].value;
        }
    }

    // Method to display the sparse matrix
    void display()
    {
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == ele[k].row && j == ele[k].colomn)
                {
                    cout << ele[k++].value;
                }
                else
                {
                    cout << "0";
                }
            }
            cout << endl;
        }
    }

    // Method to add two sparse matrices
    Sparse *add(Sparse &s2)
    {
        if (m != s2.m || n != s2.n)
            return nullptr; // Return nullptr if matrices have different dimensions

        Sparse *sum = new Sparse(m, n, num + s2.num);
        int i = 0, j = 0, k = 0;

        while (i < num && j < s2.num)
        {
            if (ele[i].row < s2.ele[j].row)
            {
                sum->ele[k++] = ele[i++];
            }
            else if (s2.ele[i].row > ele[j].row)
            {
                sum->ele[k++] = ele[j++];
            }
            else
            {
                if (ele[i].colomn < s2.ele[j].colomn)
                {
                    sum->ele[k++] = ele[i++];
                }
                else if (s2.ele[j].colomn < ele[i].colomn)
                {
                    sum->ele[k++] = s2.ele[j++];
                }
                else
                {
                    sum->ele[k] = ele[i];
                    sum->ele[k++].value = s2.ele[j++].value;
                }
            }
        }
        while (i < num)
            sum->ele[k++] = ele[i++];
        while (j < s2.num)
            sum->ele[k++] = s2.ele[j++];

        sum->num = k; // Number of elements in sum
        return sum;
    }
};

int main()
{
    int m, n, num;
    cout << "Enter dimensions for the matrix (m * n) : ";
    cin >> m;
    cout << "  by  ";
    cin >> n;
    cout << "Enter number of non zero elements in matrix: ";
    cin >> num;
    Sparse s1(m, n, num);
    s1.create();
    s1.display();
    return 0;
}