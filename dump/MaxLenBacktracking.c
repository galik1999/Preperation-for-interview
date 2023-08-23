#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 16 * 26

int maxLength(char **, int arrSize);
void backtracking(char **, int, int, char *, int *);
int validAssignment(char *, char *);

int main()
{
    char *arr[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p"};
    // char *arr[] = {"un", "iq", "ue", "ko", "pp", "pl", "bg"};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    printf("%d ", maxLength(arr, arrSize));
    return 0;
}

int maxLength(char **arr, int arrSize)
{
    int maxLen = 0;
    char concat[MAX_SIZE] = {'\0'};
    char temp[MAX_SIZE] = {'\0'};
    for (int i = 0; i < arrSize; i++)
    {
        strcat(temp, arr[i]);
    }
    if (validAssignment(temp, NULL))
    {
        return strlen(temp);
    }

    backtracking(arr, arrSize, 0, concat, &maxLen);
    return maxLen;
}

void backtracking(char **arr, int arrSize, int left, char *concat, int *maxLen)
{
    if (left == arrSize)
    {
        if (strlen(concat) > *maxLen)
        {
            *maxLen = strlen(concat);
            return;
        }
        return;
    }
    if (validAssignment(arr[left], concat))
    {
        int prevLen = strlen(concat);
        strcat(concat, arr[left]);
        *maxLen = strlen(concat) > *maxLen ? strlen(concat) : *maxLen;
        backtracking(arr, arrSize, left + 1, concat, maxLen);
        concat[prevLen] = '\0';
    }
    backtracking(arr, arrSize, left + 1, concat, maxLen);
}
// int validAssignment(char *s, char *t){
//     for (int i = 0; i < strlen(s); i++)
//     {
//         for (int j = 0; j < strlen(t); j++)
//         {
//             if((s[i] ^ t[j]) == 0){
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }

int validAssignment(char *s, char *t)
{
    int counters[26] = {0};
    for (int i = 0; i < strlen(s); i++)
    {
        counters[s[i] - 'a']++;
    }
    if (t != NULL)
    {
        for (int i = 0; i < strlen(t); i++)
        {
            counters[t[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (counters[i] > 1)
        {
            return 0;
        }
    }
    return 1;
}
