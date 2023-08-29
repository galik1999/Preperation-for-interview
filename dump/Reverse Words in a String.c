#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    char* word;
    struct Node* next;
}Node;

typedef struct {
    Node* top;
    int size;
}Stack;

Stack* createStack() {
    Stack* stack = malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;

    return stack;
}
void push(Stack** stack, char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->word = (char*)calloc(strlen(word) + 1, sizeof(char));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    newNode->next = (*stack)->top;
    (*stack)->top = newNode;
    (*stack)->size++;
}
char* pop(Stack** stack) {
    if ((*stack)->size != 0) {
        char* poppedString = (char*)calloc(strlen((*stack)->top->word) + 1, sizeof(char));
        strcpy(poppedString, (*stack)->top->word);
        Node* temp = (*stack)->top;
        (*stack)->top = (*stack)->top->next;
        free(temp->word);
        free(temp);
        (*stack)->size--;
        return poppedString;
    }
    else return NULL;
}
void freeStack(Stack** stack) {
    while ((*stack)->size != 0) {
        pop(stack);
    }
}


char* reverseWords(char* s) {
    int i = 0;
    int returnSize = 0;
    Stack* stack = createStack();
    bool firstTime = true;
    // 1. push all the words into the stack.
    while (i < strlen(s)) {
        // jump over the leading spaces.
        while (i < strlen(s) && s[i] == ' ') {
            i++;
        }
        int counter = 0;
        int j = i;
        // get the word.
        while (i < strlen(s) && s[i] != ' ') {
            counter++;
            i++;
        }
        char* currWord = (char*)calloc(counter + 2, sizeof(char));
        int k = 0;
        for (int k = 0; k < counter; k++) {
            currWord[k] = s[j++];
        }
        if (i <= strlen(s) && counter != 0) {
            if (firstTime) {
                firstTime = false;
            }
            else {
                currWord[counter] = ' ';
                counter++;
            }
        }
        if (counter != 0) {
            push(&stack, currWord);
            returnSize += counter;
        }
        free(currWord);
    }

    //2. pop all the words from the stack
    char* returnString = (char*)calloc(returnSize + 1, sizeof(char));
    while (stack->size != 0) {
        char* current = pop(&stack);
        strcat(returnString, current);
    }
    return returnString;
    freeStack(&stack);

}

int main() {
    const char* str = "  hello world  ";
    char* result = reverseWords(str);
    printf("%s\n", result);
    printf("%d\n", strlen(result));
    return 0;
}