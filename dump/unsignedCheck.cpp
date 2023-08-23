#include <stdio.h>
// when an unsigned integer "becomes negative" i.e -1,its value is very high integer ((2^32)-1).
// this happens according to the two's complement approach.

int main() {
	unsigned int i = 10;
	int flag = 1;
	while (i-- >= 0 && flag) {
		printf("%u ",i);
		if (i == -1) flag = 0;
	}
	printf("%d", i == 4294967294);
	return 0;
}