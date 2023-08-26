#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isValid(char* word, const char* row) {
    // finds a valid word to be added to the result array.
    for (int i = 0; i < strlen(word); i++) {
        char ch[2];
        ch[0] = word[i];
        ch[1] = '\0';
        if (strstr(row, ch) == NULL) {
            return false;
        }
    }
    return true;
}

char** findWords(char** words, int wordsSize, int* returnSize) {
    const char* firstRow = "qwertyuiopQWERTYUIOP";
    const char* secondRow = "asdfghjklASDFGHJKL";
    const char* thirdRow = "zxcvbnmZXCVBNM";

    int counter = 0;
    int index = 0;
    char** result = (char**)calloc(20, sizeof(char*));
    for (int i = 0; i < wordsSize; i++) {
        if (isValid(words[i], firstRow)) {
            result[index] = (char*)calloc(100, sizeof(char));
            counter++;
            strcpy(result[index++], words[i]);
        }
        else if (isValid(words[i], secondRow)) {
            result[index] = (char*)calloc(100, sizeof(char));
            counter++;
            strcpy(result[index++], words[i]);
        }
        else if (isValid(words[i], thirdRow)) {
            result[index] = (char*)calloc(100, sizeof(char));
            counter++;
            strcpy(result[index++], words[i]);
        }
    }
    *returnSize = counter;
    return result;
}


int main() {
    char* words[4] = {"Hello","Alaska","Dad","Peace"};
    int size = 0;
    char** result = findWords(words,4,&size);
    for (int i = 0; i < size; i++) {
        printf("%s\n", result[i]);
    }
    return 0;
}