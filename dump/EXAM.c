#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotateString(char *a, int n, int flag)
{
    if (flag == 0)
        return;
    char *result = (char *)calloc(n, sizeof(char));
    // if flag > 0 take elements from the end
    // if flag < 0 take elements from the start
    int counter = 0;
    if (flag > 0)
    {
        flag %= n;
        char *temp1 = (char *)calloc(flag + 1, sizeof(char));
        int k = 0;
        int i = n - (flag % n);
        while (counter < flag)
        {
            temp1[k++] = a[i++];
            counter++;
        }
        char *temp2 = (char *)calloc(n - flag + 1, sizeof(char));
        for (int j = 0; j < n - flag; j++)
        {
            temp2[j] = a[j];
        }
        // temp1 => appy
        // temp2 => i am very h
        strcpy(result, temp1);
        int p = 0;
        for (int j = strlen(result); j < n; j++)
        {
            result[j] = temp2[p++];
        }
        result[n] = '\0';

        for (int j = 0; j < n; j++)
        {
            *(a + j) = result[j];
        }
        free(temp1);
        free(temp2);
        free(result);
        return;
    }
    else
    {
        flag *= -1;
        flag %= n;
        char *temp1 = (char *)calloc(flag + 1, sizeof(char));
        int j = 0;
        for (j = 0; j < flag; j++)
        {
            temp1[j] = a[j];
        }
        char *temp2 = (char *)calloc(n - flag + 1, sizeof(char));
        int k = 0;
        for (j; j < n; j++)
        {
            temp2[k++] = a[j];
        }
        // temp1 => i am v
        // temp2 => ery happy

        strcpy(result, temp2);

        k = 0;
        for (int j = strlen(temp2); j < n; j++)
        {
            result[j] = temp1[k++];
        }
        result[n] = '\0';

        for (int j = 0; j < n; j++)
        {
            *(a + j) = result[j];
        }
        free(temp1);
        free(temp2);
        free(result);
        return;
    }
}

int main()
{
    char s1[] = "i am very happy";
    rotateString(s1, strlen(s1), -36);
    printf("%s ", s1);
    return 0;
}
