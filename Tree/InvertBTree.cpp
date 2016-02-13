#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        if (root->left)
            invertTree(root->left);
        if (root->right)
            invertTree(root->right);
        swap(root->left, root->right);
    }
};