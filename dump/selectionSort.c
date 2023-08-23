#include <stdlib.h>
#include <stdio.h>

void selectionSort(int[],int);

void printArr(int[],int,char*);

int main(){
    int arr[] = {8,9,10,88,29,285,17,27,1,28};
    int len = sizeof(arr) / sizeof(arr[0]);

    printArr(arr,len,"Unsorted array: ");

    selectionSort(arr,len);

    printArr(arr,len,"Sorted array: ");
}

void selectionSort(int arr[],int size){
    //selection sort finds the minimal value in each iteration and puts it in the arr.
    //Time Complexity: O(n^2);
    for (int i = 0; i < size; i++)
    {
        int min = arr[i];
        int index = i;
        for (int j = i; j < size; j++)
        {   
            if(arr[j] < min){
                min = arr[j];
                index=j;
            }
        }
        arr[index] = arr[i];
        arr[i] = min;    
    }
    
}

void printArr(int arr[],int size,char* name){
    //printing all the elements of the array.
    printf("%s",name);
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}