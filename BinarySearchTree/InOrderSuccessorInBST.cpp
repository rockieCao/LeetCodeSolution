#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left, *right;
        TreeNode(int x):val(x),left(NULL),right(NULL){}    
    };
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root==NULL||p==NULL) return NULL;
        
        TreeNode* successor=NULL;
        while(root!=NULL) {
            if(p->val < root->val) {
                successor=root;
                root=root->left;
            }
            else {
                root=root->right;    
            }
        }
        
        return successor;
    }
    
    static void test() {
        Solution sol;
        int n, x,val,left,right;
        while(cin>>n) {
            vector<TreeNode*> edge(n,NULL);
            for(int i=0;i<n;i++) {
                cin>>x>>val>>left>>right;
                if(left!=-1) edge[left]=new TreeNode(left);
                if(right!=-1) edge[right]=new TreeNode(right);
                if(edge[x]==NULL) edge[x]=new TreeNode(-1);
                edge[x]->val=val;
                edge[x]->left=(left==-1?NULL:edge[left]);
                edge[x]->right=(right==-1?NULL:edge[right]);
            }
            cin>>x;
            for(int i=0;i<n;i++)
                if(edge[i]!=NULL&&edge[i]->val==x) {
                    x=i;    
                }
            TreeNode *ans=sol.inorderSuccessor(edge[0],edge[x]);
            cout<<"ans="<<(ans==NULL?-1:ans->val)<<endl;
        }
    }
};
