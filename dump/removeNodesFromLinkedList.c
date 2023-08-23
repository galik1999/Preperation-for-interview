#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct ListNode
{
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

typedef struct List{
    ListNode* head;
}List;

typedef struct SNode
{
    ListNode *listNode;
    struct SNode *next;
} SNode;

typedef struct Stack
{
    SNode *top;
} Stack;

void push(Stack **stack, ListNode *node)
{
    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    newNode->listNode = node;
    newNode->next = NULL;

    if ((*stack)->top == NULL)
    {
        (*stack)->top = newNode;
        return;
    }
    newNode->next = (*stack)->top;
    (*stack)->top = newNode;
}
int pop(Stack **stack)
{
    if ((*stack)->top == NULL)
        return -1;
    SNode *temp = (*stack)->top;
    (*stack)->top = (*stack)->top->next;
    int val = temp->listNode->val;
    free(temp);
    return val;
}
void freeStack(Stack **stack)
{
    while ((*stack)->top != NULL)
    {
        SNode *temp = (*stack)->top;
        (*stack)->top = (*stack)->top->next;
        free(temp);
    }
}
bool isEmpty(Stack *stack)
{
    return stack->top == NULL;
}
void printStack(Stack* stack){
    while(stack->top != NULL){
        printf("%d\n",stack->top->listNode->val);
        stack->top = stack->top->next;
    }
}

struct ListNode *removeNodes(struct ListNode *head)
{
    if (head->next == NULL)
        return head;
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;

    push(&stack, head);
    ListNode *temp = head->next;
    while (temp != NULL)
    {
        if (temp->val <= stack->top->listNode->val)
        {
            push(&stack, temp);
        }
        else
        {
            while (!isEmpty(stack) && temp->val > stack->top->listNode->val)
            {
                pop(&stack);
            }
            push(&stack, temp);
        }
        temp = temp->next;
    }
    // printStack(stack);
    ListNode *newHead = (ListNode*)malloc(sizeof(ListNode));
    newHead->next = NULL;
    newHead->val = pop(&stack);
    while(!isEmpty(stack)){
        int val = pop(&stack);
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->val = val;
        node->next = newHead;
        newHead = node;
    }
    return newHead;
}

int main()
{
    ListNode n5 = {.val=8,.next=NULL};
    ListNode n4 = {.val=3,.next=&n5};
    ListNode n3 = {.val=13,.next=&n4};
    ListNode n2 = {.val=2,.next=&n3};
    ListNode n1 = {.val=5,.next=&n2};

    ListNode* answer = removeNodes(&n1);
    while(answer!=NULL){
        ListNode* temp = answer;
        printf("%d ",answer->val);
        answer = answer->next;
        free(temp);
    }

    return 0;
}