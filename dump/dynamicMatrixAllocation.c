#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    //dynamic allocation of matrix.
    int size;
    printf("Please enter the size of the matrix :\n");
    scanf("%d",&size);

    //first allocate the double pointer which saves the rows of the matrix.
    int** matrix = (int**) malloc(sizeof(int*)*size);
    if(matrix == NULL){
        exit(-1);
    }
    for (int i = 0; i < size; i++)
    {
        //for each row allocate array which saves the values of the row.
        *(matrix + i) = (int*) malloc(sizeof(int)*size);
        if(*(matrix + i) == NULL){
            exit(-1);
        }
    }

    //initialize the matrix with random numbers from 1 to size-1.
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int num = rand() % size + 1;
            *(*(matrix+i) + j) = num;
        }
    }

    //print the values of the matrix.
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ",*(*(matrix + i)+j));
        }
        printf("\n");  
    }

    //free the memory allocated for the program.
    //first free each row.
    //second free the main arr.  
    for (int i = 0; i < size; i++)
    {
        free(*(matrix+i));
    }
    free(matrix);
    
    return 0;
}
