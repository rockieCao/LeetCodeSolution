#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) return ret;

        queue<TreeNode*> que;
        que.push(root);
        int count = 1;
        while (!que.empty())
        {
            TreeNode *cur = que.front();
            que.pop();
            --count;

            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);

            if (count == 0)
            {
                count = que.size();
                ret.push_back(cur->val);
            }
        }

        return ret;
    }
};