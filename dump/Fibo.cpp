#include <stdio.h>
#include <stdlib.h>


void recPrintFib(int n,int first,int second,int third) {
	if (n > 0) {
		third = first + second;
		first = second;
		second = third;

		printf("%d ", third);
		recPrintFib(n - 1, first, second, third);
	}
}
int iterPrintFib(int n) {
	// Dynamic Programming aproach.
	if (n == 1) {
		printf("%d", 0);
		return 0;
	}
	if (n == 2) {
		printf("%d", 1);
		return 0;
	}
	int* arr = (int*)malloc(sizeof(int) * n);
	if (arr != NULL) {
		arr[0] = 0;
		arr[1] = 1;
		printf("%d %d ", arr[0], arr[1]);
		for (int i = 2; i < n; i++) {
			arr[i] = arr[i - 1] + arr[i - 2];
			printf("%d ", arr[i]);
		}
		free(arr);
		return 0;
	}
	return 1;
}

int main() {
	void(*fibo1)(int,int,int,int);
	fibo1 = &recPrintFib;
	printf("%d %d ", 0,1);
	fibo1(8-2,0,1,1);

	printf("\n");

	int(*fibo2)(int);
	fibo2 = &iterPrintFib;
	fibo2(8);

	return 0;
}