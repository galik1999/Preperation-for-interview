#include <stdio.h>

typedef long ll;

int func(void) {
	static int counter;
	counter++;
	return counter;
}


int main() {
	printf("%d\n", func());
	printf("%d\n", func());

	printf("address of func: %p\n", &func);
	printf("address of func: %p\n", func);
	return 0;
}