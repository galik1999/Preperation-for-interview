#include <stdio.h>
#include <stdlib.h>


void add(int a,int b){
    printf("the sum of %d and %d is: %d",a,b, a+b);
}
void multiply(int a,int b){
    printf("the product of %d and %d is:%d ",a,b,a*b);
}
void sub(int a,int b){
    printf("the difference between %d and %d is: %d",a,b,a-b);
}

int main(){
    //initialization of a pointer to an array of functions which get.
    // ptr to function is always void.
    void (*operation_func_arr[])(int,int) = {add,multiply,sub};
    unsigned int ch;
    int a = 15,b = 20;
    printf("enter operation:\n1 = add\n2 = multiply\n3 = substract \n");
    scanf("%d",&ch);
    if(ch > 3){
        printf("Not Supported.\n");
        return 0;
    }
    (*operation_func_arr[ch-1])(a,b);

    return 0;
}