#include <iostream>
using namespace std;

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int ans = searchDepth(root);
        return ans>=0;
    }

    int searchDepth(TreeNode* root) {
        if (root==NULL) return 0;
        int leftD=0,rightD=0;
        if (root->left!=NULL) leftD=searchDepth(root->left);
        if (leftD<0) return -1; //not balanced
        if (root->right!=NULL) rightD=searchDepth(root->right);
        if (rightD<0) return -1; //not balanced
        if (abs(leftD-rightD)>1)
            return -1;
        return 1+max(leftD,rightD);
    }
};