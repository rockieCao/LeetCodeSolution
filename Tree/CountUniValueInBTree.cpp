#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Problem in folder
// Give a BTree, find number of subtrees whose nodes are with same value
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    int countUnivalSubtrees(TreeNode* root) {
        int ret = 0;
        search(root, ret);
        return ret;
    }

    bool search(TreeNode* root, int& ret) {
        if (root == NULL) return true;
        bool left = search(root->left, ret);
        bool right = search(root->right, ret);
        if (!left ||!right) return false;
        if (root->left!=NULL&&(root->val)!=(root->left->val))
            return false;
        if (root->right!=NULL&&(root->val)!=(root->right->val))
            return false;
        ret++;
        return true;
    }

    static TreeNode* buildTree(vector<int> levorder)
    {
        //bfs
        queue<TreeNode *> que;
        TreeNode *root = new TreeNode(levorder[0]);
        TreeNode *cp = root;
        que.push(cp);
        for (int i = 1; i < levorder.size(); i++)
        {
            cp = que.front();
            que.pop();

            if (levorder[i]!=-100)
            {
                cp->left = new TreeNode(levorder[i]);
                que.push(cp->left);
            }
            ++i;
            if (levorder[i]!=-100)
            {
                cp->right = new TreeNode(levorder[i]);
                que.push(cp->right);
            }
        }

        return root;
    }

    static void visit(TreeNode *root) {
        if (root == NULL) return;
        cout<<(root->val)<<",";
        visit(root->left);
        visit(root->right);
    }

    static void test() {
        int n, x;
        vector<int> levorder;
        cin>>n;
        TreeNode *root = NULL;
        for (int i = 0; i < n; i++)
        {
            cin>>x; //-100 means no child
            levorder.push_back(x);
        }
        cout<<"build tree ..."<<endl;
        root=buildTree(levorder);
        cout<<"build tree done."<<endl;
        visit(root);
        cout<<endl;
        cout<<"count univalue subtrees ..."<<endl;
        cout<<"result = "<<Solution().countUnivalSubtrees(root)<<endl;
    }
};