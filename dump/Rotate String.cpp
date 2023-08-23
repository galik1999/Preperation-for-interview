#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void shift(char* s) {
	//shifting the string by moving the leftmost letter to the rightmost position.
	int leftMostLetter = s[0];
	for (int i = 1; i < strlen(s); i++) {
		s[i - 1] = s[i];
	}
	s[strlen(s) - 1] = leftMostLetter;
}

bool rotateString(char* s, char* goal) {
	// 1. shift the string n times.
	// 2. if one of the result of the shift equals goal -> return true.
	// else return false.
	if (strcmp(s, goal) == 0) return true;
	for (int i = 0; i < strlen(s); i++) {
		shift(s);
		printf("%s\n",s);
		if (strcmp(s, goal) == 0) return true;
	}
	return false;
}

int main() {
	char s[] = "abcde";
	char goal[] = "cdeab";
	//printf("%d", rotateString(s, goal));

	// a much faster solution.
	// concatenation of the two strings will contain all possible shifts of s. 
	if (strlen(s) != strlen(goal)) return false;
	char* res = (char*)calloc(2 * strlen(s)+1, sizeof(char));
	if (res != NULL) {
		strcpy(res, s);
		strcat(res, s);
		bool result = false;
		if (strstr(res, goal) != NULL) {
			result = true;
			printf("True");
		}
		else {
			printf("False");
		}
	}
	free(res);
	return 0;
}