#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == NULL) return ret;

        vector<int> curPath(1,root->val);
        search(root, curPath, ret);

        return ret;
    }

    void search(TreeNode* root, vector<int> &curPath, vector<string> &ret) {
        if (root == NULL) return;
        if (root->left==NULL && root->right==NULL)
        {
            stringstream ss;
            ss<<curPath[0];
            for (int i = 1; i < curPath.size(); i++)
                ss<<"->"<<curPath[i];
            string str;
            ss>>str;
            ret.push_back(str);
            return;
        }

        if (root->left)
        {
            curPath.push_back(root->left->val);
            search(root->left, curPath, ret);
            curPath.pop_back();
        }
        if (root->right)
        {
            curPath.push_back(root->right->val);
            search(root->right, curPath, ret);
            curPath.pop_back();
        }
    }
};