#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    //Node of the linked list which implements the queue.
    int val;
    struct Node* next;
}Node;

typedef struct Queue{
    //manager struct which saves the head and the tail of the queue.
    Node* head;
    Node* tail;
}Queue,*pQueue;

//insert new node to the queue.
void insert(pQueue*,int);

//delete from the head.
void delete(pQueue*);

//print all the Queue
void printQueue(pQueue*);

//free the memory allocated for the queue.
void freeQueue(pQueue*);

int main(){
    pQueue queue = (pQueue)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    insert(&queue,5);
    insert(&queue,10);
    insert(&queue,20);
    insert(&queue,30);
    insert(&queue,40);

    printQueue(&queue);

    // printf("%d\n",queue->head->val);
    // printf("%d\n",queue->tail->val);

    delete(&queue);
    // printf("%d\n",queue->head->val);

    printQueue(&queue);
    insert(&queue,200);
    printQueue(&queue);

    freeQueue(&queue);
    return 0;
}

void insert(pQueue* ptr,int val){
    //insert the new node to the tail of the queue.
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    if((*ptr)->head == NULL && (*ptr)->tail == NULL){
        (*ptr)->head = newNode;
        (*ptr)->tail = newNode;
        return;
    }
    (**ptr).tail->next = newNode;
    (**ptr).tail = newNode;
}

void delete(pQueue* queue){
    //delete the node from the head of the queue.
    if((*queue)->head == NULL){
        printf("The queue is empty.\n");
        return;
    }
    Node* temp = (**queue).head;
    (*queue)->head = (*queue)->head->next;
    free(temp);
}


void printQueue(pQueue* queue){
    //print all the values of the queue.
    Node* temp = (**queue).head;
    while(temp != NULL){
        if(temp->next == NULL){
            printf("%d\n",temp->val);
            break;
        }
        printf("%d -> ",temp->val);
        temp = temp->next;
    }
}

void freeQueue(pQueue* queue){
    //free the memory allocated for the queue.
    while((*queue)->head != NULL){
        Node* temp = (*queue)->head;
        (*queue)->head = (*queue)->head->next;
        free(temp);
    }
    printf("Queue memory deallocation completed successfully.\n");
}