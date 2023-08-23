#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

typedef struct List
{
    ListNode *head;
} List;

// get the node at the given index.
ListNode *get(List *list, int index);

// get the index of the specified node;
int indexOf(List *list, ListNode *node);

// sorts the given list.
void sortList(List **list, int l, int m, int r);

// merges two sorted lists.
void mergeLists(List **list, int l, int m, int r);

// allocates memory for the new node.
ListNode *createNode(int val);

// inserts a node to list before the position.
bool insert(List **list, int position, ListNode *node);

// free List
void freeList(List **list);

// print the list
void printList(List *list,char* msg)
{
    printf("%s ",msg);
    ListNode *temp = list->head;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("%d \n", temp->val);
            return;
        }
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
}

int calcLen(ListNode *head);

int main()
{
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    ListNode *n1 = createNode(3);
    ListNode *n2 = createNode(1);
    ListNode *n3 = createNode(2);
    ListNode *n4 = createNode(4);
    insert(&list, 0, n1);
    insert(&list, 0, n2);
    insert(&list, 0, n3);
    insert(&list, 0, n4);


    printList(list,"Unsorted List: ");

    int size = calcLen(list->head);
    sortList(&list, 0, (size - 1) / 2, size - 1);

    printList(list,"Sorted List: ");

    freeList(&list);
    return 0;
}

void sortList(List **list, int l, int m, int r)
{
    if (l < r)
    {
        sortList(list, l, (m + l) / 2, m);
        sortList(list, m + 1, (m + r + 1) / 2, r);

        mergeLists(list, l, m, r);
    }
}

void mergeLists(List **list, int l, int m, int r)
{
    List *firstList = (List *)malloc(sizeof(List));
    firstList->head = NULL;
    List *secondList = (List *)malloc(sizeof(List));
    secondList->head = NULL;
    List *mergedList = (List *)malloc(sizeof(List));
    mergedList->head = NULL;

    for (int i = m; i >= l; i--)
    {
        ListNode *node = createNode((*get(*list, i)).val);
        insert(&firstList, 0, node);
    }
    for (int i = r; i > m; i--)
    {
        ListNode *node = createNode((*get(*list, i)).val);
        insert(&secondList, 0, node);
    }
    // printList(firstList);
    // printList(secondList);
    int k = 0;
    while (firstList->head != NULL && secondList->head != NULL)
    {
        if (firstList->head->val < secondList->head->val)
        {
            ListNode *node = createNode((*get(firstList, 0)).val);
            insert(&mergedList, k++, node);
            firstList->head = firstList->head->next;
        }
        else
        {
            ListNode *node = createNode((*get(secondList, 0)).val);
            insert(&mergedList, k++, node);
            secondList->head = secondList->head->next;
        }
    }
    while (firstList->head != NULL)
    {
        ListNode *node = createNode((*get(firstList, 0)).val);
        insert(&mergedList, k++, node);
        firstList->head = firstList->head->next;
    }
    while (secondList->head != NULL)
    {
        ListNode *node = createNode((*get(secondList, 0)).val);
        insert(&mergedList, k++, node);
        secondList->head = secondList->head->next;
    }

    // printList(mergedList);
    ListNode *temp = mergedList->head;
    ListNode *replacer = get(*list, l);
    int i = l;
    int size = r - l + 1;
    while (i < l + size)
    {
        replacer->val = temp->val;
        temp = temp->next;
        replacer = replacer->next;
        i++;
    }

    free(firstList);
    free(secondList);
    free(mergedList);
}

int calcLen(ListNode *head)
{
    ListNode *temp = head;
    int counter = 0;
    while (temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}
bool insert(List **list, int position, ListNode *node)
{
    // insertion to head;
    if (position < 0)
    {
        return false;
    }
    if (position == 0)
    {
        node->next = (*list)->head;
        (*list)->head = node;
        return true;
    }
    // insertion to the body.
    ListNode *prev = (*list)->head;
    int k = 0;
    while (k < position - 1 && prev != NULL)
    {
        prev = prev->next;
        k++;
    }
    if (prev == NULL)
    {
        return false;
    }
    node->next = prev->next;
    prev->next = node;
    return true;
}
void freeList(List **list)
{
    // free all the memory allocated for the storage of the list.
    while ((*list)->head != NULL)
    {
        ListNode *temp = (*list)->head;
        (*list)->head = (*list)->head->next;
        free(temp);
    }
    free(*list);
}
ListNode *createNode(int val)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

ListNode *get(List *list, int index)
{
    ListNode *temp = list->head;
    int counter = 0;
    while (counter < index && temp != NULL)
    {
        temp = temp->next;
        counter++;
    }
    return temp;
}
int indexOf(List *list, ListNode *node)
{
    ListNode *temp = list->head;
    int counter = -1;
    while (temp != node && temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}