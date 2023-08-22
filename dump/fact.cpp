#include <stdio.h>

int fact(int n) {
	if (n == 0) {
		return 1;
	}
	return n * fact(n - 1);
}


int main() {
	printf("%d\n",fact(15));
	printf("%d\n", fact(6));
	printf("%d\n", fact(7));
}