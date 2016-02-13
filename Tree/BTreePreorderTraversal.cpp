#include <iostream>
#include <stack>
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

    vector<int> preorderTraversal(TreeNode* root) { //non-recursive version
        vector<int> ret;
        if (root == NULL) return ret;
        
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();
            ret.push_back(cur->val);

            if (cur->right)
                st.push(cur->right);
            if (cur->left)
                st.push(cur->left);
        }

        return ret;
    }

    vector<int> preorderTraversal2(TreeNode* root) { //morris version
        vector<int> ret;
        if (root == NULL) return ret;

        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur != NULL) {
            if (cur->left == NULL) {
                ret.push_back(cur->val);
                cur = cur->right;
            }
            else {
                pre = cur->left;
                while (pre->right != NULL & pre->right != cur) {
                    pre = pre->right;
                }
                if (pre->right == NULL) {
                    ret.push_back(cur->val);
                    pre->right = cur;
                    cur = cur->left;
                }
                else {
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return ret;
    }

    vector<int> preorderTraversal3(TreeNode* root) { //recursive version
        vector<int> ret;
        
        search(root, ret);

        return ret;
    }

    void search(TreeNode* root, vector<int>& ret) {
        if (root == NULL) return;

        ret.push_back(root->val);
        search(root->left, ret);
        search(root->right, ret);
    }
};