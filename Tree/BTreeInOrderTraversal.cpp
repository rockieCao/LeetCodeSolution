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

    vector<int> inorderTraversal(TreeNode *root) { //backtrack version: time O(n), space O(logN)
        stack<TreeNode*> st;
        vector<int> ret;
        TreeNode* cur = root;
        while (cur!=NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top();
                st.pop();
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }

        return ret;
    }

    vector<int> inorderTraversal2(TreeNode *root) { //morris version: time O(n), space O(1)
        vector<int> ret;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur) {
            if (cur->left == NULL) {
                ret.push_back(cur->val);
                cur = cur->right;
            }
            else {
                pre = cur->left;
                while (pre->right != NULL && pre->right != cur) {
                    pre = pre->right;
                }

                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                }
                else {
                    pre->right = NULL;
                    ret.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
    }
};