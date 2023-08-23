#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
	int i;
	for (i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}


int main() {
	int k = 8;
	
	if (isPrime(k) == 1) {
		printf("%d is prime",k);
	}
	else {
		printf("%d is not prime", k);
	}
	return 0;
}