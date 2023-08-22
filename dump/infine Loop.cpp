#include<stdio.h>
int main()
{
	int n;
	// n is decremented twice each iteration hence the condition n!=0 will be bypassed 
	// and the the loop will run infinetely. 
	for (n = 7; n != 0; n--)
		printf("n = %d", n--);
	getchar();
	return 0;
}
