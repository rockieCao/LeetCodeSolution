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

    bool hasPathSum(TreeNode* root, int sum) {
        if (root==NULL) return sum==0;
        if (root->left==NULL&&root->right==NULL) return root->val == sum;

        return hasPathSum(root->left, sum-(root->val))||hasPathSum(root->right, sum-(root->val));
    }
};