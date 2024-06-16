#include <stdio.h>

void recursion1(int n){
    if(n>0){
        printf("%d\t",n);
        recursion1(n-1); //Called as tail recursion.
    }
}
// void recursion2(int fog){
//     if(fog>0){
//         recursion2(fog-2);//called as head Recursion
//         printf("%d\t ",fog);
//     }
// }
int main(){
    int x=8;
    recursion1(x); //Output ----> 8 7 6 5 4 3 2 1  

    // recursion2(x); //Output ----> 2 4 6 8 This is because in function first the recursive function is called then printing is done.First the call of previous function is made and completed then the process of printing is done. 
    //---> In recursion1 printing is done at calling time while in recursion 2 printing is done at returning time.


    return 0;
}