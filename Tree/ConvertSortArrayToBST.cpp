#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    TreeNode *sortedArrayToBST(vector<int> &num) {
        int n = num.size();
        if (n == 0) return NULL;
        
        return convert(num, 0, n-1);
    }

    TreeNode *convert(vector<int> &num, int s, int t) {
        if (s>t) return NULL;
        int mid = s+(int)((t-s+1)/2);
        TreeNode *tn = new TreeNode(num[mid]);
        tn->left = convert(num, s, mid-1);
        tn->right = convert(num, mid+1, t);

        return tn;
    }
};