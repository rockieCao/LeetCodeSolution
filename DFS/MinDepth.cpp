#include <iostream>
using namespace std;

// test case:
// [0] -> 1
// [1,2] -> 2
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    int minDepth(TreeNode* root) {
        if (root==NULL) return 0;
        int ans = 1;
        search(root, 1, ans);

        return ans;
    }

    void search(TreeNode *root, int depth, int &ans) {
        if ((root->left==NULL && root->right==NULL) || (ans>1&&depth>=ans))
        {
            if (depth<ans||ans==1) ans = depth;
            return;
        }

        if (root->left)
            search(root->left, depth+1, ans);
        if (root->right)
            search(root->right, depth+1, ans);
    }
};