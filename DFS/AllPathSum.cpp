#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if (root == NULL) return ret;
        vector<int> curPath(1,root->val);
        search(root, curPath, sum-(root->val), ret);

        return ret;
    }

    void search(TreeNode* root, vector<int> &curPath, int sum, vector<vector<int>> &ret) {
        if (root == NULL) return;
        if (root->left==NULL && root->right==NULL) {
            if (0 == sum)
                ret.push_back(curPath);
            return;
        }
        if (root->left)
        {
            curPath.push_back(root->left->val);
            search(root->left, curPath, sum-(root->left->val), ret);
            curPath.pop_back();
        }
        if (root->right)
        {
            curPath.push_back(root->right->val);
            search(root->right, curPath, sum-(root->right->val), ret);
            curPath.pop_back();
        }
    }
};