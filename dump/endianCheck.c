#include <stdio.h>

int main(){
    //check if the system is LE or BE.
    int n = 1;
    if(*(char*)&n == 1){
        printf("Little Endian.");
        return 0;
    }
    printf("Big Endian.");
    return 0;
}