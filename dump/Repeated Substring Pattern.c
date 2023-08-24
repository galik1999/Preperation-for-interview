#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
bool repeatedSubstringPattern(char* s) {
    int i = 0;
    for (int j = i; j < strlen(s); j++) {
        int subLength = j - i + 1;
        if (strlen(s) % subLength != 0 || strlen(s) == subLength) continue;
        int times = strlen(s) / subLength;
        char* substring = (char*)calloc(subLength + 1, sizeof(char));
        for (int a = i; a <= j; a++) {
            substring[a - i] = s[a];
        }
        char* check = (char*)calloc(times * subLength + 1, sizeof(char));
        for (int k = 0; k < times; k++) {
            strcat(check, substring);
        }
        if (strcmp(check, s) == 0) {
            free(substring);
            free(check);
            return true;
        }
        free(substring);
        free(check);
    }

    return false;
}

int main() {
    char* str = "abcabcabcabc";
    printf("%d", repeatedSubstringPattern(str));
	return 0;
}