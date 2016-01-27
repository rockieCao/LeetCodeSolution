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

    TreeNode* pre; // need to be maintained globally
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        pre = NULL;

        return check(root);
    }

    bool check(TreeNode* root) { // in-order check
        if (root == NULL) return true;

        bool ret = true;
        if (root->left) {
            ret = check(root->left);
            if (!ret) return ret;
        }
        if (pre != NULL) {
            ret = (root->val)>(pre->val);
            if (!ret) return ret;
        }
        pre = root;
        ret = check(root->right);
        return ret;
    }


};