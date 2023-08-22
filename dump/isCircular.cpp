#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node* next;
}Node;

typedef struct List {
	Node* head;
	Node* tail;
}List;

void addToTail(List** list,int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->val = val;
		newNode->next = (*list)->head;
		if ((*list)->head == NULL) {
			(*list)->head = newNode;
			(*list)->tail = newNode;
		}
		else {
			(*list)->tail->next = newNode;
			(*list)->tail = newNode;
		}
	}
}
void printList(List* list) {
	if (list->head == NULL) {
		return;
	}
	Node* temp = list->head->next;
	printf("%d ", list->head->val);
	while (temp != NULL && temp!= list->head) {
		printf("%d ", temp->val);
		temp = temp->next;
	}
	if (temp == list->head) {
		printf("%d \n", list->head->val);
	}
}

bool isCircularList(List* list) {
	if (list->head == NULL) {
		return true;
	}
	Node* temp = list->head->next;
	while (temp != NULL && temp != list->head) {
		temp = temp->next;
	}
	return temp == list->head;
}



int main() {
	List list = {NULL,NULL};
	List* ptrList = &list;
	addToTail(&ptrList, 5);
	addToTail(&ptrList, 10);
	addToTail(&ptrList, 15);
	addToTail(&ptrList, 20);
	addToTail(&ptrList, 25);
	printList(ptrList);

	if (isCircularList(&list) == 1) {
		printf("The List is Circular\n");
	}
	else {
		printf("The List is NOT Circular\n");
	}
	return 0;
}