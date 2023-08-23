#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

struct QNode{
    TreeNode* treeNode;
    struct QNode* next;
    int level;
};

typedef struct{
    struct QNode* head;
    struct QNode* tail;
    int size;
}Queue;

typedef struct QNode QNode;

void enqueue(Queue** queue,TreeNode* treeNode,int level){
    QNode* node = (QNode*)malloc(sizeof(QNode));
    node->treeNode = treeNode;
    node->next = NULL;
    node->level = level;
    if((*queue)->head == NULL && (*queue)->tail == NULL){
        (*queue)->head = node;
        (*queue)->tail = node;
        (*queue)->size++;
        return;
    }
    (*queue)->tail->next = node;
    (*queue)->tail = node;
    ((*queue)->size)++;
    return;
}
bool dequeue(Queue** queue,TreeNode** returnValue,int* level){
    if((*queue) == NULL) return false;
    if((*queue)->head == NULL) return false;
    *returnValue = (**queue).head->treeNode;
    *level = (**queue).head->level;
    (*queue)->head = (*queue)->head->next;
    if((*queue)->head == NULL){
        (*queue)->tail = NULL;
    }
    ((**queue).size)--;
    return true; 
}
void freeQueue(Queue** queue){
    while((*queue)->head != NULL){
        QNode* temp = (*queue)->head;
        (*queue)->head = (*queue)->head->next;
        free(temp);
    }
    (*queue)->size = 0;
}
bool isEmpty(Queue* queue){ return queue->size == 0;}

int treeHeight(TreeNode* root){
    if(root == NULL) return -1;

    int left = treeHeight(root->left);
    int right = treeHeight(root->right);

    return left > right? left+1:right+1;
}

double* averageOfLevels(struct TreeNode* root, int* returnSize){
    Queue* q =(Queue*)malloc(sizeof(Queue));
    q->head = NULL; 
    q->tail = NULL;
    q->size = 0;
    int height = treeHeight(root);
    double* arr = (double*)calloc(height+1,sizeof(double));
    int* counters = (int*)calloc(height+1,sizeof(int));
    enqueue(&q,root,0);
    while(!isEmpty(q)){
        TreeNode* temp;
        int level;
        dequeue(&q,&temp,&level);
        if(temp != NULL){
            arr[level]+=temp->val;
            counters[level]++;
            if(temp->left != NULL) enqueue(&q,temp->left,level+1);
            if(temp->right != NULL) enqueue(&q,temp->right,level+1);
        }
    }
    for(int i=0;i<=height;i++){
        arr[i] = arr[i] / counters[i];
    }
    free(counters);
    freeQueue(&q);
    *returnSize = height+1;
    return arr;
}

int main(){
    TreeNode n5 = {.val = 7, .left = NULL , .right=NULL};
    TreeNode n4 = {.val = 15, .left = NULL , .right=NULL};
    TreeNode n3 = {.val = 20, .left = &n4 , .right=&n5};
    TreeNode n2 = {.val = 9, .left = NULL , .right=NULL};
    TreeNode n1 = {.val = 3, .left = &n2 , .right=&n3};

    int returnSize;
    double* answer = averageOfLevels(&n1,&returnSize); 

    for (int i = 0; i < returnSize; i++)
    {
        printf("%lf ",answer[i]);
    }
    
    free(answer);
    return 0;
}
