/*
Given a 8 bit variable, return its reflection.
Example:
    input:  00101100
    output: 00110100
*/
#include <stdio.h>
#include <math.h>

int mirror(int);

int main(){
    // printf("%d\n",mirror(3));
    printf("%d\n",mirror(1));
    printf("%d\n",mirror(2));
    printf("%d\n",mirror(4));
    printf("%d\n",mirror(8));
    printf("%d\n",mirror(16));
    printf("%d\n",mirror(32));
    printf("%d\n",mirror(64));
    printf("%d\n",mirror(128));
    return 0;
}

int mirror(int num){
    //reverses the bits of the given num.
    unsigned int mask = 1;
    unsigned int pos = 128;
    int result = 0;
    for (int i = 0; i < 8; i++)
    {
        if((num & mask) == mask){
            result = result | pos;
        }
        mask *= 2;
        pos /= 2;
    }
    return result;
}
