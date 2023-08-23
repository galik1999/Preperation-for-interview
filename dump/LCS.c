#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//BRUTE FORCE.
//Time Complexity: O(2^n).
int longestCommonSubsequence(char *text1, char *text2)
{
    if (strcmp(text1, "") == 0 || strcmp(text2, "") == 0)
        return 0;
    if (strlen(text1) == 1 && strlen(text2) == 1)
    {
        if (text1[0] == text2[0])
            return 1;
        return 0;
    }
    if (text1[0] == text2[0])
    {
        return 1 + longestCommonSubsequence(text1 + 1, text2 + 1);
    }
    else
    {
        int lcs1 = longestCommonSubsequence(text1 + 1, text2);
        int lcs2 = longestCommonSubsequence(text1, text2 + 1);
        int lcs3 = longestCommonSubsequence(text1 + 1, text2 + 1);

        int max = lcs1;
        max = lcs2 > max ? lcs2 : max;
        max = lcs3 > max ? lcs3 : max;
        return max;
    }
}

int allPossibleSequences(char* text){
    if(text == NULL) return 0;
    if(strlen(text) == 1) return 1;
    return 1+2*allPossibleSequences(text+1);
}

int main()
{
    char *s1 = "abcdefghijklmnopqrstuvwxyz";
    printf("All Possible Subsequences of %s: %d\n",s1, allPossibleSequences(s1));
    char *s2 = "acegijkrstyz";
    printf("All Possible Subsequences of %s: %d\n",s2, allPossibleSequences(s2));
    int lcs = longestCommonSubsequence(s1, s2);
    printf("Longest Common Subsequence: %d\n", lcs);
    return 0;
}