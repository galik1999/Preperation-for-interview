//includes of header files.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//function declaration
void getData(int[]);
void printData(int[]);
void printPrimary(int[]);
bool isPrime(int);

int main(){
    // print all prime numbers in the array
    int arr[10];
    getData(arr);
    printData(arr);
    printPrimary(arr);
    
    return 0;
}

void getData(int arr[]){
    // scan all the values from the user
    for (int i = 0; i < 10; i++)
    {
        if(!scanf("%d",&(arr[i]))){
            exit(-1);
        }
    } 
}
void printData(int arr[]){
    // print all the values of the arr
    for (int i = 0; i < 10; i++)
    {
        if(!printf("%d ",arr[i])){
            exit(-1);
        }
    } 
    printf("\n"); 
}

void printPrimary(int arr[]){
    //print all the prime numbers if the array.
    printf("The primary numbers are: ");
    for (int i = 0; i < 10; i++)
    {
        if(isPrime(arr[i])){
            printf("%d ",arr[i]);
        }
    } 
}

bool isPrime(int num){
    //isParimary returns true if num is prime, otherwise returns false.
    //Time Complexity: O(sqrt(n)) where n is num.
    if(num == 1){
        return false;
    }
    if(num == 2){
        return  true;
    }
    for (int i = 2; i <= (double)ceil(sqrt(num)) ; i++)
    {
        if(!(num % i)){
            return false;
        }
    }
    return true;
    
}

