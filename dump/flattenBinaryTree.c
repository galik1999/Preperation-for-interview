#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

void preOrder(TreeNode* root,TreeNode** newRoot);
void flatten_pre_order(struct TreeNode *root);
void flatten_recursive(struct TreeNode *root);
void printRightTree(TreeNode* root);
void insertRight(TreeNode** newRoot,int val);

int main()
{

    TreeNode n6 = {.val = 60, .left = NULL, .right = NULL};
    TreeNode n5 = {.val = 50, .left = NULL, .right = NULL};
    TreeNode n4 = {.val = 40, .left = NULL, .right = NULL};
    TreeNode n3 = {.val = 30, .left = &n6, .right = NULL};
    TreeNode n2 = {.val = 20, .left = &n4, .right = &n5};
    TreeNode n1 = {.val = 10, .left = &n2, .right = &n3};

    TreeNode *root = &n1;

    printRightTree(root);

    void(*f)(TreeNode*) = flatten_recursive;
    f(root);

    printRightTree(root);

    return 0;
}

void flatten_pre_order(struct TreeNode* root){
    TreeNode* newRoot = NULL;
    preOrder(root,&newRoot);
    if(newRoot != NULL){
        *root = *newRoot;
    }
}

void preOrder(TreeNode* root,TreeNode** newRoot){
    if(root == NULL){
        return;
    }
    insertRight(newRoot,root->val);
    preOrder(root->left,newRoot);
    preOrder(root->right,newRoot);
}
void insertRight(TreeNode** newRoot,int val){
    if(*newRoot == NULL){
        *newRoot = (TreeNode*)malloc(sizeof(TreeNode));
        (*newRoot)->val = val;
        (*newRoot)->left = NULL;
        (*newRoot)->right = NULL;
        return;
    }
    TreeNode* temp = *newRoot;
    while(temp->right != NULL){
        temp = temp->right;
    }
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left=NULL;
    newNode->right=NULL;
    temp->right = newNode;
    temp->left = NULL;
    return;
}
void printRightTree(TreeNode* root){
    TreeNode* temp = root;
    while(temp != NULL){
        printf("%d ",temp->val);
        temp = temp->right;
    }
    printf("\n");

}
void flatten_recursive(struct TreeNode* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    flatten_recursive(root->left);
    flatten_recursive(root->right);

    TreeNode* temp = root->right;
    TreeNode* find = root;
    root->right = root->left;
    root->left = NULL;
    while(find->right != NULL){
        find = find->right; 
    } 
    find->right = temp;
}