#include <iostream>
#include <string>
using namespace std;

// problem is in the folder
class BSTIterator {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    TreeNode* UpsideDownBinaryTree(TreeNode* root) { 
        if (root == NULL) return NULL;
        TreeNode* pre = root, *sibling = root->right, *cur = root->left;
        while (cur != NULL) {
            TreeNode* tp = cur->right, *nxt = cur->left;
            cur->right = pre;
            cur->left = sibling;
            pre = cur;
            sibling = tp;
            cur = nxt;
        }
        root->left = NULL;
        root->right = NULL;
        return pre;
    }
};