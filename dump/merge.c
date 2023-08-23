#include <stdio.h>
#include <stdlib.h>

int *merge(int[], int, int[], int);

int main()
{
    // merge function implementation.
    int a1[] = {1, 100, 101, 200, 300};
    int a2[] = {2, 50, 90, 100, 200};
    int expected[] = {1, 2, 50, 90, 100, 100, 101, 200, 200, 300};

    int a1Len = sizeof(a1) / sizeof(a1[0]);
    int a2Len = sizeof(a2) / sizeof(a2[0]);
    int *result = merge(a1, a1Len, a2, a2Len);

    int len = a1Len + a2Len;
    for (int i = 0; i < len; i++)
    {
        if (result[i] != expected[i])
        {
            printf("test failed.\n");
            return 0;
        }
    }
    printf("test passed.\n");
    return 0;
}

int *merge(int left[], int leftSize, int right[], int rightSize)
{
    // merging two sorted arrays.
    int *res = (int *)malloc(sizeof(int) * (leftSize + rightSize));
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize)
    {
        if (left[i] < right[j])
        {
            res[k++] = left[i];
            i++;
        }
        else
        {
            res[k++] = right[j];
            j++;
        }
    }
    while (i < leftSize)
    {
        res[k++] = left[i];
        i++;
    }
    while (j < rightSize)
    {
        res[k++] = right[j];
        j++;
    }
    return res;
}