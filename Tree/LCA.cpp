#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st1, st2;
        search(root, p, st1);
        search(root, q, st2);

        while (st1.size()>st2.size()) st1.pop();
        while (st2.size()>st1.size()) st2.pop();
        while (st1.top() != st2.top()) { st1.pop(); st2.pop(); }

        return st1.top();
    }

    bool search(TreeNode* root, TreeNode* target, stack<TreeNode*>& st) {
        if (root == NULL) return false;
        st.push(root);
        if (root == target) return true;
        bool ret = false;
        if (root->left)
            ret = search(root->left, target, st);
        if (!ret && (root->right))
            ret = search(root->right, target, st);
        if (ret) return true;
        else {
            st.pop();
            return false;
        }
    }
};