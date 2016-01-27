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

    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;

        int sum = 0;
        search(root, 0, sum);
        return sum;
    }

    void search(TreeNode* root, int prev, int &sum) {
        if ((root->left==NULL)&&(root->right==NULL)) {
            sum+=prev*10+(root->val);
            return;
        }
        if (root->left)
            search(root->left, prev*10+(root->val), sum);
        if (root->right)
            search(root->left, prev*10+(root->val), sum);
    }
};