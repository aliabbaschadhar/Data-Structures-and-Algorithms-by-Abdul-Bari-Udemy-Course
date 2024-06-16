#include <stdio.h>

int fun(int n){
    if(n>0){
        printf("Calling : %d\t",n);  //Calling time printing (Ascending )
        int result =fun(n-1)*2; //any expression used will also be applied only at returning time.
        printf("Returning: %d\t",n);   //Returning time printing(Decending)
        return result;
    }
    return n;
}

int main(){
    int x=5;
    fun(5);
    return 0;
}