#include <stdio.h>
#include <stdbool.h>

int countPrimeSetBits(int left, int right);
bool isPrime(int);

int main() {
    printf("%d \n", countPrimeSetBits(10, 15));
    printf("%d \n", countPrimeSetBits(6, 10));
    return 0;
}

int countPrimeSetBits(int left, int right) {
    //
    int counter = 0;
    while (left <= right) {
        // count the number of set bits of the given number.
        int setBitsCounter = 0;
        unsigned int mask = 1;
        int curr = left;
        for (int i = 0; i < 32; i++) {
            if ((curr & mask) == 1) {
                setBitsCounter++;
            }
            curr = curr >> 1;
        }
        if (isPrime(setBitsCounter)) {
            counter++;
        }
        left++;
    }
    return counter;
}
bool isPrime(int n){
    if (n == 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
