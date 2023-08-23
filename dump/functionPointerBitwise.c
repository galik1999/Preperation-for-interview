#include <stdlib.h>
#include <stdio.h>

void xor(int a,int b){
    printf("xor result: %d",a ^ b);
}
void and(int a,int b){
    printf("and result: %d",a & b);
}
void or(int a,int b){
    printf("or result: %d",a | b);
}
// Generic bitwise operation function
void bitwiseOperation(void (*f)(int,int),int a, int b){
    f(a,b);
}

int main(){
    void (*bitwise_functions[])(int,int) = {xor,and,or};
    bitwiseOperation(or,2,3);
}