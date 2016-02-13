#include <iostream>
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

    vector<TreeNode*> generateTrees(int n) {
        return search(n,1,n);
    }

    vector<TreeNode*> search(int n, int s, int t) {
        vector<TreeNode*> ret;        
        if (n == 0) { ret.push_back(NULL); return ret; }
        if (n == 1) {
            TreeNode* root = new TreeNode(s);
            ret.push_back(root);
            return ret;
        }
        for (int i = s; i <= t; i++) {
            vector<TreeNode*> leftVec = search(i-s, s, i-1);
            vector<TreeNode*> rightVec = search(t-i, i+1, t);
            for (int lefti = 0; lefti < leftVec.size(); lefti++) {
                for (int righti = 0; righti < rightVec.size(); righti++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftVec[lefti];
                    root->right = rightVec[righti];
                    ret.push_back(root);
                }
            }
        }
    }
};