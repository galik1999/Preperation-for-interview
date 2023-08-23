#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10

void printArray(int[]);

int compare(const void*,const void*);

int main(){
    srand(time(NULL));
    int arr[SIZE]={0};
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % SIZE + 1;
    }
    printArray(arr);

    qsort(arr,SIZE,sizeof(int),compare);

    printArray(arr);
    
}
void printArray(int arr[]){
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}