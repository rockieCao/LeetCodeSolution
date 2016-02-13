#include <iostream>
#include <vector>
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

    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> ret;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            cur = st.top();
            if (pre == NULL || pre->left == cur || pre->right == cur) {
                if (cur->left)
                    st.push(cur->left);
                else if (cur->right)
                    st.push(cur->right);
                else {
                    ret.push_back(cur->val);
                    st.pop();
                }
            }
            else if (pre == cur->left) {
                if (cur->right)
                    st.push(cur->right);
                else {
                    ret.push_back(cur->val);
                    st.pop();
                }
            }
            else if (pre == cur->right) {
                ret.push_back(cur->val);
                st.pop();
            }
            pre = cur;
        }

        return ret;
    }

    void reverseList(TreeNode* from, TreeNode* to) {
        if (from == to) return;
        TreeNode *pre = from, *cur = from->right, *nxt;
        while (pre!=to) {
            nxt = cur->right;
            cur->right = pre;
            pre = cur;
            cur = nxt;
        }
    }

    void visitReverse(TreeNode* from, TreeNode* to, vector<int>& ret) {
        //reverse from->to
        reverseList(from, to);

        //visit
        TreeNode* cur = to;
        while (cur) {
            ret.push_back(cur->val);
            if (cur == from) break;
            cur = cur->right;
        }

        //reverse back
        reverseList(to, from);
    }

    vector<int> postorderTraversal(TreeNode *root) { //morris version: time O(n), space O(1)
        vector<int> ret;
        TreeNode dump(0); //virtual root
        dump.left = root;
        TreeNode* cur = &dump;
        TreeNode* pre = NULL;
        while (cur != NULL) {
            if (cur->left == NULL)
                cur = cur->right;
            else {
                pre = cur->left;
                while (pre->right!=NULL && pre->right!=cur) {
                    pre = pre->right;
                }
                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                }
                else {
                    visitReverse(cur->left, pre, ret);
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }

        return ret;
    }
};