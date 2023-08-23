#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char findTheDifference(char * s, char * t);
int main(){
    char* s = "abcd";
    char* t = "dbace";
    printf("%c",findTheDifference(s,t));
    return 0;
}

char findTheDifference(char * s, char * t){
    int size = strlen(s)+strlen(t);
    char* res = (char*)malloc(sizeof(char)*size);
    strcpy(res,s);
    strcat(res,t);
    int letter = 0;
    for(int i=0;i<strlen(res);i++){
        letter^=(int)res[i];
    }
    return (char)letter;
}