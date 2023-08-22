#include <stdio.h>

int main() {
	//xor swapping algorithm.
	int a = 5;
	int b = 6;
	printf("value of a :%d \n", a);
	printf("value of b :%d \n", b);
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
	printf("value of a :%d \n", a);
	printf("value of b :%d \n", b);
}