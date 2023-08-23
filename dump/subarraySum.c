#include <stdio.h>
#include <stdlib.h>

#define N 8

int *sub_array_sum(int[],int);

int main()
{
    int S = 400;
    int arr[] = {1, 2, 3, 7, 5,300,400,100};
    int* result = sub_array_sum(arr,S);
    if(result[0] == -1){
        printf("No such subarray.\n");
    }
    else{
        printf("%d %d",result[0],result[1]);
    }
    // printf("%d",sizeof(arr) / sizeof(arr[0]));
    // printf("%d",*(&arr+1)-arr); // hack
    return 0;
}
int *sub_array_sum(int arr[],int S)
    //searches for indexes of subarray which sums up to given S.
    // Time Complexity: O(n^2);
{
    int i = 0, j = 0;
    int sum = 0;
    while(i<N && j<N){
        sum+=arr[j];    
        if(sum == S){
            int* res = (int*)malloc(sizeof(int)*2);
            res[0] = i+1;
            res[1] = j+1;
            return res;
        }
        if(sum > S){
            i+=1;
            j=i;
            sum = 0;
        }
        else{
            j++;
            if(j == N){
                i+=1;
                j=i;
                sum = 0;
            }
        }
    }
    int *failed = (int*)malloc(sizeof(int));
    *failed = -1;
    return failed;
}
