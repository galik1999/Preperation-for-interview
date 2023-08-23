#include <stdio.h>
#include <stdlib.h>

// int to string converter function.
char *itos(int);

// calculate the number of digits in num.
int digits(int);

int main(void)
{
    int x = -999;
    char* str = itos(x);
    printf("num is %s\n", str); // Should print 1234
    free(str);

    //example.
    printf("int: %d\n",5 + '0');
    printf("char: %c\n",5 + '0');
    return 0;
}

int digits(int num)
{
    // calculates the number of digits in num.
    if (num < 0)
    {
        num *= -1;
    }
    int counter = 0;
    while (num != 0)
    {
        counter++;
        num /= 10;
    }
    return counter;
}

char *itos(int num)
{
    /*
    1. calculate the number of digits in num.
    2. allocate space for the string to store each digit.
    3. save each digit in the string.
    */
   if(num == 0){
    char* str = (char*)malloc(sizeof(char)+1);
    str[0]='0';
    str[1] = '\0';
    return str;
   }
   //if the number is positive we just need one extra cell for the string - for the '\0'.
   //if the number is negative we need another cell for the minus sign '-'.
   //string_size_ext is used for handeling these situations.
   int string_size_ext = 1;
   if(num<0){
    num*=-1;
    string_size_ext+=1;
   }
    int size = digits(num);
    char *str = (char *)malloc(sizeof(char) * size + string_size_ext);
    if (str == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(-1);
    }
    int i = size + string_size_ext-2;
    str[size+string_size_ext-1] = '\0';
    while (num != 0)
    {
        //adding zero character to the int digit will result in summing the coresponding ascii codes.
        // the output of summing int digit + '0' is char which equals to the int digit.
        //for example: 5 + '0' = '5'.
        //explanation: the ascii codes are summed up. 5 + 48 = 53. The char which coresponds to 53 is '5'.
        //this method works converting from char to int and int to char with digits from 0 to 9.  
        str[i--] = (num % 10)+'0';
        num /= 10;
    }
    if(string_size_ext == 2){
        str[i] = '-';
    }
    return str;
}