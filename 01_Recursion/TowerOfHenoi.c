#include <stdio.h>

// Function to solve the Tower of Hanoi
void TOH(int n, int A, int B, int C)
{
    // Base case: If there is only one disk to move
    if (n > 0)
    {
        // Move n - 1 disks from A to B
        TOH(n - 1, A, C, B);

        // Move the nth disk from A to C
        printf("( from %d to %d )\t", A, C);

        // Move n - 1 disks from B to C
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    // Solve the Tower of Hanoi for 3 disks
    TOH(3, 1, 2, 3);

    return 0;
}