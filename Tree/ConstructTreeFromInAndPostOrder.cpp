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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int iLen = inorder.size(), pLen = postorder.size();
        if (iLen == 0 || iLen != pLen) return NULL;

        imap.clear();
        for (int i = 0; i < iLen; i++)
        {
            imap[inorder[i]]=i;
        }

        return createTree(inorder, 0, iLen-1, postorder, 0, pLen-1);
    }

    TreeNode* createTree(vector<int>& inorder, int iStart, int iEnd, vector<int>& postorder, int pStart, int pEnd) {
        if (iStart > iEnd || pStart > pEnd)
            return NULL;
        TreeNode *cp = new TreeNode(postorder[pEnd]);
        int idx = imap[postorder[pEnd]];

        cp->left = createTree(inorder, iStart, idx-1, postorder, pStart, pStart+idx-iStart-1);
        cp->right = createTree(inorder, idx+1, iEnd, postorder, pEnd-(iEnd-idx), pEnd-1);

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
        vector<int> inorder, postorder;
        cin>>n;
        for (int i = 0; i<n;i++)
        {
            cin>>x;
            inorder.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            postorder.push_back(x);
        }
        Solution sol;
        TreeNode* root = sol.buildTree(inorder, postorder);
        visit(root);
    }
};