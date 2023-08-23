#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int *returnSize, int **columnsReturnSize);

int main()
{
    int returnSize;
    int *columnsReturnSize;
    int **matrix = createMatrix(&returnSize, &columnsReturnSize);
    printf("%d ",returnSize);
    printf("%d ",columnsReturnSize);

    return 0;
}

int **createMatrix(int *returnSize, int **columnsReturnSize)
{
    int **matrix = (int **)calloc(3, sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        matrix[i] = (int *)calloc(3, sizeof(int));
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = i * 3 + j;
        }
    }
    *returnSize = 3;
    
    return matrix;
}