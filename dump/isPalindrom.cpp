#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isPalindrom(const char* str) {
	if (strlen(str) <=  1) {
		return true;
	}
	int left = 0;
	int right = strlen(str) - 1;
	while (left < right) {
		if (str[left] != str[right]) return false;
		left++;
		right--;
	}
	return true;

}
bool derPalindrom(const char* str) {
	if (strlen(str) <= 1) {
		return true;
	}
	if (str[0] == str[strlen(str) - 1]) {
		char* copy = (char*)calloc(strlen(str), sizeof(char));
		if (copy != NULL) {
			for (int i = 1; i < strlen(str) - 1; i++) {
				copy[i - 1] = str[i];
			}
			bool res = derPalindrom(copy);
			free(copy);
			return res;
		}
	}
	return false;
}

int main() {
	printf("%d \n", isPalindrom("abcdefedcba"));
	printf("%d \n", isPalindrom(""));
	printf("%d \n", isPalindrom("a"));
	printf("%d \n", isPalindrom("ab"));
	printf("%d \n", isPalindrom("abcbag"));
	return 0;
}