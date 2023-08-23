#include <stdlib.h>
#include <stdio.h>
#include <math.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
typedef struct TreeNode TreeNode;
int treeHeight(TreeNode*);
void DFS(TreeNode* root,int currentSum, int *sum);
int sumRootToLeaf(struct TreeNode* root);
int main(){
    TreeNode n4 = {.val = 1, .left = NULL, .right = NULL};
    TreeNode n3 = {.val = 1, .left = NULL, .right = NULL};
    TreeNode n2 = {.val = 0, .left = &n4, .right = NULL};
    TreeNode n1 = {.val = 1, .left = &n2, .right = &n3};

    printf("%d",sumRootToLeaf(&n1));
    return 0;
}

int sumRootToLeaf(struct TreeNode* root){
    int sum=0;
    int currentSum = 0;
    DFS(root,0,&sum);
    return sum;
}

void DFS(TreeNode* root,int currentSum,int *sum){
    if(root == NULL)return;
    if(root->left == NULL && root->right == NULL){
        //calculate the binary number created in arr and add it to *sum.
        currentSum = (currentSum << 1) | (root->val);
        *sum+=currentSum;
        return;
    }
    currentSum = (currentSum << 1) | (root->val);
    DFS(root->left,currentSum,sum);
    DFS(root->right,currentSum,sum);
}