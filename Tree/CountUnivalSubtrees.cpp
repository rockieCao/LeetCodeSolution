#include<iostream>
#include<vector>
using namespace std;

/*Problem: Count Unival Subtrees
Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.

For example:
 Given binary tree,

              5
             / \
            1   5
           / \   \
          5   5   5

return 4.
*/

class Solution{
public:
    struct TreeNode{
        int val;
        TreeNode *left, *right;
        TreeNode():val(-1),left(NULL),right(NULL){}
        TreeNode(int _v,TreeNode* _l,TreeNode* _r):val(_v),left(_l),right(_r){}   
    };
    
    int countUnivalSubtrees(TreeNode* root) {
        int cnt=0;
        search(root, cnt);
        return cnt;
    }
    
    bool search(TreeNode *root, int& cnt) {
        if(root==NULL) return true;
        if(root->left==NULL&&root->right==NULL) {
            ++cnt;
            return true;   
        }
        bool lf=search(root->left, cnt);
        bool rt=search(root->right, cnt);
        if(lf&&rt&&(root->left==NULL||root->left->val==root->val)&&(root->right==NULL||root->right->val==root->val)) {
            ++cnt;
            return true;   
        }
        return false;
    }
    
    static void visit(TreeNode *root) {
        if(root==NULL) cout<<">>>NULL"<<endl;
        else 
        {
            cout<<">>>"<<root->val<<endl;
            visit(root->left);
            visit(root->right);
        }
    }
    
    static void test() {
        int n;
        Solution sol;
        while(cin>>n) {
            vector<TreeNode*> nodes;
            for(int i=0;i<n;++i) nodes.push_back(new TreeNode(-1,NULL,NULL));
            int x,val, left,right;
            for(int i=0;i<n;++i) {
                cin>>x>>val>>left>>right;
                nodes[x]->val=val;
                if(left!=-1)
                    nodes[x]->left=nodes[left];
                else nodes[x]->left=NULL;
                if(right!=-1)
                    nodes[x]->right=nodes[right];
                else nodes[x]->right=NULL;
            }
            
            visit(nodes[0]);
            cout<<"ans="<<sol.countUnivalSubtrees(nodes[0])<<endl;
        }
    }
};

