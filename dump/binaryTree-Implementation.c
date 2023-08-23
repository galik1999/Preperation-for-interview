#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    //node of the tree.
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef struct Tree{
    //manager struct for the tree data structure.
    TreeNode* root;
}Tree;

//insert a value into the tree.
void insert(TreeNode**,int);

//print all the values of the tree inorder.
void inOrder(TreeNode**,void(*)(int));

//free the memory allocated for the tree.
void freeTree(TreeNode**);

//sorting array with BST
void tree_sort(int[],int);

//----------------------------------------------------------------//
//functions for in order
void inOrder_print(int val){
    printf("%d ",val);
}

//----------------------------------------------------------------//
void inOrder_addToArr(TreeNode** root,int* index,int arr[]){
    if(*root == NULL){
        return;
    }
    inOrder_addToArr(&(*root)->left,index,arr);
    arr[(*index)++] = (*root)->val;
    inOrder_addToArr(&(*root)->right,index,arr);
}

void printArr(int arr[],int size,char* message){
    printf("%s",message);
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

int main(){
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    insert(&tree->root,10);
    insert(&tree->root,11);
    insert(&tree->root,3);
    insert(&tree->root,200);
    insert(&tree->root,29);
    insert(&tree->root,14);
    insert(&tree->root,7);
    insert(&tree->root,70);
    insert(&tree->root,58);
    insert(&tree->root,90);

    printf("In Order tree traversal: \n");
    inOrder(&(tree->root),inOrder_print);
    freeTree(&tree->root);
    printf("\n");

    printf("---------------------------------------------------------\n");
    int arr[] = {7,19,58,100,200,50,67,83,12,3};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArr(arr,len,"Unsorted array: ");
    printf("\n");
    tree_sort(arr,len);
    printArr(arr,len,"sorted array: ");

    return 0;
}

void insert(TreeNode** root,int val){
    //insert the value in the binary srach tree.
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    //insert a value into the binary search tree.
    if(*root == NULL){
        *root = node;
        return;
    }
    val < (*root)->val ? insert(&(*root)->left,val) : insert(&(*root)->right,val);
}
void inOrder(TreeNode** root,void(*operation)(int)){
    if(*root == NULL){
        return;
    }
    inOrder(&(*root)->left,operation);
    operation((*root)->val);
    inOrder(&(*root)->right,operation);
}

void tree_sort(int arr[],int size){
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    for (int i = 0; i < size; i++)
    {   
        insert(&tree->root,arr[i]);
    }
    int index = 0;
    inOrder_addToArr(&tree->root,&index,arr);
    freeTree(&tree->root);
    
}
void freeTree(TreeNode** root){
    //post order freeing of the nodes in the tree.
    if((*root) == NULL){
        return;
    }
    freeTree(&(*root)->left);
    freeTree(&(*root)->right);
    free(*root);
}

