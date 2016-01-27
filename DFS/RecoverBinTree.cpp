#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    void recoverTree2(TreeNode* root) {
        if (root == NULL) return;

        vector<TreeNode*> tmp;
        inorder2(root, tmp);
        //check
        for(TreeNode* p : tmp)
            cout<<p->val<<",";
        cout<<endl;
        int first=-1, second=-1;
        for (int i = 1; i < tmp.size(); i++) {
            if (tmp[i-1]->val>tmp[i]->val) {
                if (first==-1) first=i-1;
                second = i;
            }
        }
        swap(tmp[first]->val, tmp[second]->val);
        
        return;
    }

    void inorder2(TreeNode* root, vector<TreeNode*> &ret) {
        if (root == NULL) return;
        if (root->left) {
            inorder2(root->left, ret);
        }
        ret.push_back(root);
        if (root->right) {
            inorder2(root->right, ret);
        }
    }
    
    TreeNode *first, *second, *pre;
    void recoverTree(TreeNode* root) {
        if (root == NULL) return;
        
        first = NULL;
        second = NULL;
        pre = NULL;

        inorder(root);
        swap(first->val,second->val);
        return;
    }

    void inorder(TreeNode* root) {
        if (root == NULL) return;
        if (root->left) inorder(root->left);
        if (pre!=NULL && pre->val > root->val)
        {
            if (first==NULL) first = pre;
            second = root;
        }
        pre = root;
        if (root->right) inorder(root->right);
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

            if (levorder[i]!=-1)
            {
                cp->left = new TreeNode(levorder[i]);
                que.push(cp->left);
            }
            ++i;
            if (levorder[i]!=-1)
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
            cin>>x; //-1 means no child
            levorder.push_back(x);
        }
        cout<<"build tree ..."<<endl;
        root=buildTree(levorder);
        cout<<"build tree done."<<endl;
        visit(root);
        cout<<endl;
        cout<<"recover tree ..."<<endl;
        Solution().recoverTree(root);
        cout<<"recover tree done."<<endl;
        visit(root);
        cout<<endl;
    }
};