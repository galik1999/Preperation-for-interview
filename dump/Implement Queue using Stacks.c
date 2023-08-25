#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* next;
}Node;

typedef struct Stack {
    int size;
    Node* top;
}Stack;
 

typedef struct MyQueue {
    Stack* s1;
    Stack* s2;
} MyQueue;

void push(Stack** stack, Node* node) {
    if ((*stack)->size == 0) {
        (*stack)->top = node;
    }
    else {
        node->next = (*stack)->top;
        (*stack)->top = node;
    }
    (*stack)->size++;
}
void pop(Stack** stack) {
    Node* temp = (*stack)->top;
    (*stack)->top = (*stack)->top->next;
    free(temp);
    (*stack)->size--;
}
void freeStack(Stack** stack) {
    while ((*stack)->top != NULL) {
        Node* temp = (*stack)->top;
        (*stack)->top = (*stack)->top->next;
        free(temp);
        (*stack)->size--;
    }
}

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->s1 = (Stack*)malloc(sizeof(Stack));
    queue->s1->size = 0;
    queue->s1->top = NULL;
    queue->s2 = (Stack*)malloc(sizeof(Stack));
    queue->s2->size = 0;
    queue->s2->top = NULL;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = x;
    newNode->next = NULL;
    push(&(obj->s1), newNode);
}

void moveElements(Stack** dest, Stack** source) {
    // moving all elements from stack source to stack dest.
    while ((*source)->size != 0) {
        Node* curr = (Node*)malloc(sizeof(Node));
        curr->next = NULL;
        curr->val = (*dest)->top->val;
        pop(source);
        push(dest, curr);
    }
}


int myQueuePop(MyQueue* obj) {
    //moving all elements from the first queue to the second queue.
    moveElements(obj->s2, obj->s1);
    // pop from the second stack and return that popped value.
    int retVal = obj->s2->top->val;
    pop(&(obj->s2));
    // returning all the elements from the second queue to the first queue.
    moveElements(obj->s1, obj->s2);

    return retVal;
}

int myQueuePeek(MyQueue* obj) {
    //moving all elements from the first queue to the second queue.
    moveElements(obj->s2, obj->s1);
    // pop from the second stack and return that popped value.
    int retVal = obj->s2->top->val;
    // returning all the elements from the second queue to the first queue.
    moveElements(obj->s1, obj->s2);
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->s1->size == 0 && obj->s2->size == 0;
}

void myQueueFree(MyQueue* obj) {
    freeStack(&(obj->s1));
    freeStack(&(obj->s2));
    free(obj);
}
