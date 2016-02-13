#include <iostream>
#include <stack>
using namespace std;

class BSTIterator {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    TreeNode* cur;
    stack<TreeNode*> st;
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur != NULL || !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        int ret = -1;
        while (cur!=NULL||!st.empty()) {
            if (cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top();
                st.pop();
                ret = cur->val;
                cur = cur->right;
            }
        }
        return ret;
    }
};