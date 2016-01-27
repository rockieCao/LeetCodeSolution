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

    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        return isSameTree(root, root);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL)) return false;
        if (p==NULL&&q==NULL) return true;
        if (p->val != q->val) return false;
        return isSameTree(p->left,q->right)&&isSameTree(p->right,q->left);
    }
};