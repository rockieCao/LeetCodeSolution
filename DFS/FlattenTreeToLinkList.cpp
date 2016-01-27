#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// test cases:
// [0] -> 0
// [1,2,-1] -> 1,2
// [1,2,5,3,4,-1,6] -> 1,2,3,4,5,6
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    TreeNode *preptr;

    void flatten(TreeNode* root) {
        if (root == NULL) return;
        TreeNode *tp = root->right;
        if (preptr!=NULL)
        {
            preptr->left = NULL;
            preptr->right = root;
        }
        preptr = root;
        if (root->left)
            flatten(root->left);
        if (tp)
            flatten(tp);
        return;
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
        cout<<"flatten tree ..."<<endl;
        Solution().flatten(root);
        cout<<"flatten tree done."<<endl;
        TreeNode *tp = root;
        while (tp!=NULL)
        {
            cout<<tp->val<<",";
            tp=tp->right;
        }
        cout<<endl;
    }
};