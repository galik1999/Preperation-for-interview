#include <string.h>
#include <stdio.h>

int numJewelsInStones(char* jewels, char* stones) {
    // defining counter arrays for storage of the amount of each exising jewel in jewels.
    int smallLettersCounters[26] = { 0 };
    int bigLettersCounters[26] = { 0 };
    int counter = 0;
    // counting the appearance of each jewel in jewels.
    for (int i = 0; i < strlen(jewels); i++) {
        if (jewels[i] >= 'a' && jewels[i] <= 'z') smallLettersCounters[jewels[i] - 'a']++;
        else if (jewels[i] >= 'A' && jewels[i] <= 'Z') bigLettersCounters[jewels[i] - 'A']++;
    }
    // counting how much appearances of jeweles there are in our stones arsenal and saving the result in "counter".
    for (int i = 0; i < strlen(stones); i++) {
        char stone = stones[i];
        if (stones[i] >= 'a' && stones[i] <= 'z' && smallLettersCounters[stone - 'a'])counter++;
        else if (stones[i] >= 'A' && stones[i] <= 'Z' && bigLettersCounters[stone - 'A'])counter++;
    }
    return counter;
}

int main() {
    char jewels[] = "aA";
    char stones[] = "aAAbbbb";
    printf("%d\n",numJewelsInStones(jewels,stones));
    return 0;
}