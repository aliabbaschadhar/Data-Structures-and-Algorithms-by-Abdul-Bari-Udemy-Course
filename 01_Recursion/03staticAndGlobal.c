#include <stdio.h>

// Static variable in recursive function ... Only one copy will be formed of s
//  int fun1(int n){
//      int static s=0;
//      if(n>0){
//          s++;
//          return fun1(n-1)+s;
//      }
//      return 0;
//  }

// int main()
// {
//     int x=3;
//     printf("%d\n",fun1(x)); // Output : 9
//     return 0;
// }

// Global variable in recursive function acts same as static variable in recursive function.
#include <stdio.h>
int x = 0; // Value of global variable will remain global.
int fun(int n)
{
    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}
int main()
{
    int r;
    r = fun(5);
    printf("%d\n", r); // 25

    r = fun(5);
    printf("%d\n", r); // 50

    return 0;
}
