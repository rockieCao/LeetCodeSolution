#include <iostream>
using namespace std;

// Problem in folder
// Given a BST and a value K, find a node in BST which is closest to K.
class BSTIterator {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    TreeNode* closestBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;
        
        int ans = abs((root->val)-val);
        TreeNode* ansP = root;
        TreeNode* cp = root;
        while (cp)
        {
            int delta = abs((cp->val)-val);
            if (delta < ans) {
                ans = delta;
                ansP = cp;
            }
            if (cp->val > val) {
                cp = cp->left;
            }
            else {
                cp = cp->right;
            }
        }

        return ansP;
    }
};