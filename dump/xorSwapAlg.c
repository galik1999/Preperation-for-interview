#include <stdlib.h>
#include <stdio.h>


int main(){
    //xor switch algorithm
    int a = 2, b = 3;
    printf("a = %d , b = %d\n", a,b);
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    printf("a = %d , b = %d", a,b);
}