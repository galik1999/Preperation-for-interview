#include <stdio.h>
#include <stdlib.h>

int nCk(int n, int k);
long fact(int n);
int **combine(int n, int k, int *returnSize, int **returnColumnSizes);
void add(int *arr, int curr, int **result, int *i, int *j, int k);
void backtrack(int arr[], int size, int group[], int left, int tempk, int *i, int *j, int **result, int k);

void rec(int arr[], int size, int group[], int left, int k,int originalK)
{
    if (left > size)
    {
        return;
    }
    if (k == 0)
    {
        // check which indecies participate in the group
        printf("{");
        int index = 0;
        for (int i = 0; i < size; i++)
        {
            if (group[i] == 1)
            {
                if(index == originalK-1){
                    printf("%d", arr[i]);
                }
                else{
                    printf("%d,", arr[i]);
                }
                index++;
            }
        }
        printf("}");
        // print them
    }
    else
    {
        group[left] = 1;
        rec(arr, size, group, left + 1, k - 1,originalK);
        group[left] = 0;
        rec(arr, size, group, left + 1, k,originalK);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int group[] = {0, 0, 0, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    // rec(arr,size,group,0,3,3);
    int returnSize;
    int* returnColumnSizes;
    int** res = combine(4,2,&returnSize,&returnColumnSizes);
    for(int i=0;i<returnSize;i++){
        printf("{");
        for(int j=0;j<returnColumnSizes[i];j++){
            if(j == returnColumnSizes[i] - 1){
                printf("%d",res[i][j]);
            }
            else{
                printf("%d,",res[i][j]);
            }
        }
        printf("}");    
    }
    free(res);
    free(returnColumnSizes);
    return 0;
}

int **combine(int n, int k, int *returnSize, int **returnColumnSizes)
{
    *returnSize = nCk(n,k);
    *returnColumnSizes = (int*)calloc(*returnSize,sizeof(int));
    for(int i=0;i<*returnSize;i++){
        (*returnColumnSizes)[i] = k;
    }
    //backtrack to find all combinations.
    int ** result = (int**)calloc(*returnSize,sizeof(int*));
    for(int i=0;i<*returnSize;i++){
        result[i] = (int*)calloc(k,sizeof(int));
    }
    int* arr = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        arr[i] = i+1;
    }
    int* group = (int*)calloc(n,sizeof(int));
    int i = 0;
    int j = 0;
    backtrack(arr,n,group,0,k,&i,&j,result,k);
    return result;

}
int nCk(int n, int k)
{
    return (fact(n)) / (fact(n - k) * fact(k));
}

long fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}
void backtrack(int arr[], int size, int group[], int left, int tempk, int *i, int *j, int **result, int k)
{
    if (tempk == 0)
    {
        // check which indecies participate in the group
        // printf("{");
        for (int p = 0; p < size; p++)
        {
            if (group[p] == 1)
            {
                // printf("%d ", arr[p]);
                add(arr, p, result, i, j, k);
            }
        }
        // printf("}");
        // print them
    }
    else if(left < size)
    {
        group[left] = 1;
        backtrack(arr, size, group, left + 1, tempk - 1, i, j, result, k);
        group[left] = 0;
        backtrack(arr, size, group, left + 1, tempk, i, j, result, k);
    }
}

void add(int *arr, int curr, int **result, int *i, int *j, int k)
{
    // add current complete permutation to the result array.
    if (result[*i] == NULL)
    {
        result[*i] = (int *)calloc(k, sizeof(int));
    }
    result[*i][*j] = arr[curr];
    if (*j + 1 == k)
    {
        (*i)++;
        *j=0;
    }
    else
    {
        (*j)++;
    }
}
