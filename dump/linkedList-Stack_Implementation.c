#include <stdlib.h>
#include <stdio.h>
//Stack impementation with linked list.

typedef struct Node{
    // Node of Linked List.
    int val;
    struct Node* next;
}Node;

typedef struct LinkedList{
    Node* head;   
}LinkedList;

//adding new node to the list's head. Push element to the stack.
void push(LinkedList**,int val);
//printing the elements of the list.
void printStack(Node*);
//removing the first element from the list. Pop from the stack.
int pop(LinkedList**);
//free the memory
int freeStack(LinkedList**);

int main(){
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    push(&list,1);  
    push(&list,2);
    push(&list,3);
    push(&list,4);
    push(&list,5);
    push(&list,6);
    push(&list,7);

    printStack(list->head);  
    int popped1 = pop(&list);
    printStack(list->head);  
    int popped2 = pop(&list);
    printStack(list->head); 

    push(&list,200);
    printStack(list->head);

    freeStack(&list);

}
int pop(LinkedList** list){
    //pop element from the head of the list.
    if((**list).head == NULL){
        printf("The list is Empty.\n");
        return -1;
    }
    Node* temp = (*list)->head;
    int val = temp->val;
    (*list)->head = (*list)->head->next;
    free(temp);
    if(val != - 1){
        printf("%d was removed from the list.\n",val);
    }
    return val;
}

void push(LinkedList** list,int val){
    //push element to the head of the list.
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    if((**list).head == NULL){
        newNode->next = NULL;
        (**list).head = newNode;
        return;
    }
    newNode->next = (**list).head;
    (**list).head = newNode;
}

void printStack(Node* head){
    //print all the elements of the list, seperated by  "->".
    Node* temp = head;
    while(temp != NULL){
        if(temp->next == NULL){
             printf("%d\n",temp->val);
             break;
        }
        printf("%d -> ",temp->val);
        temp = temp->next;
    }
}
int freeStack(LinkedList** list){
    //free the memory allocated for the stack.
    while((**list).head != NULL){
        Node* temp = (**list).head;
        (**list).head = (**list).head->next;
        free(temp);
    }
    printf("Memory deallocation completed successfully.\n");
}


