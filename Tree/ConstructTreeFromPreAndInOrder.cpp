#include <iostream>
#include <vector>
#include <unordered_map>
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
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    unordered_map<int, int> imap;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int iLen = inorder.size(), pLen = preorder.size();
        if (iLen == 0 || iLen != pLen) return NULL;

        imap.clear();
        for (int i = 0; i < iLen; i++)
        {
            imap[inorder[i]]=i;
        }

        return createTree(inorder, 0, iLen-1, preorder, 0, pLen-1);
    }

    TreeNode* createTree(vector<int>& inorder, int iStart, int iEnd, vector<int>& preorder, int pStart, int pEnd) {
        if (iStart > iEnd || pStart > pEnd)
            return NULL;
        TreeNode *cp = new TreeNode(preorder[pStart]);
        int idx = imap[preorder[pStart]];

        cp->left = createTree(inorder, iStart, idx-1, preorder, pStart+1, pStart+idx-iStart);
        cp->right = createTree(inorder, idx+1, iEnd, preorder, pEnd-(iEnd-idx)+1, pEnd);

        return cp;
    }

    static void visit(TreeNode* root)
    {
        if (root == NULL) return;
        
        visit(root->left);
        cout<<" "<<root->val;
        visit(root->right);
    }

    static void test() {
        int n, x;
        vector<int> inorder, preorder;
        cin>>n;
        for (int i = 0; i<n;i++)
        {
            cin>>x;
            inorder.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            preorder.push_back(x);
        }
        Solution sol;
        TreeNode* root = sol.buildTree(inorder, preorder);
        visit(root);
    }
};