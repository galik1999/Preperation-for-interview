#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

void reverseList(ListNode **);
ListNode* recurse(ListNode *);

void printList(ListNode*,const char*);


int main()
{
    ListNode *n1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *n2 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *n3 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *n4 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *n5 = (ListNode *)malloc(sizeof(ListNode));
    n1->val = 10;
    n2->val = 20;
    n3->val = 30;
    n4->val = 40;
    n5->val = 50;

    n1->next = n2;
    n2->next = n3;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    printList(n1,"Original List: ");
    reverseList(&n1);
    printf("\n");
    printList(n1,"Reversed List: ");
}

void reverseList(ListNode** head){
    ListNode* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    recurse(*head);
    *head = temp;
}

ListNode* recurse(ListNode *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    if(head->next->next == NULL){
        //swap between the nodes.
        ListNode* temp = head->next;
        temp->next = head;
        head = temp;
        head->next->next = NULL;
        return head;
    } 
    ListNode* temp = recurse(head->next);
    temp->next->next = head;
    head->next = NULL;
    return temp->next;
    
}

void printList(ListNode* head,const char* desc){
    printf("%s",desc);
    ListNode* temp = head;
    while(temp != NULL){
        if(temp->next == NULL){
            printf("%d",temp->val);
            return;
        }
        printf("%d->",temp->val);
        temp = temp->next;
    }
}