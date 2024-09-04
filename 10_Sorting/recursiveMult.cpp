#include <iostream>
using namespace std;
int Mult(int a, int b)
{
    int x, y;
    if (b == 1)
    {
        return a;
    }
    else
    {
        y = b - 1;
        x = Mult(a, y);
        return x + a;
    }
}
int main()
{
    cout << Mult(3, 2) << endl;
    return 0;
}