#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if ((root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL)) {
            return false;
        }
        if (root1 == NULL && root2 == NULL) {
            return true;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return true && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            cout << q.front() << endl;
            if ((q.front()->val == subRoot->val) && (isSameTree(q.front(), subRoot))) {
                return true;
            }
            if (q.front()->left != nullptr) q.push(q.front()->left);
            if (q.front()->right != nullptr) q.push(q.front()->right);
            q.pop();
        }
        return false;
    }

};