#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

/*Problem: Binary Tree Upside Down
Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
For example:
 Given a binary tree {1,2,3,4,5},
  1
 / \
 2  3
/ \
4 5

return the root of the binary tree [4,5,2,#,#,3,1].
  4
 / \
 5  2
   / \
   3 1

Solution: recursive or use stack to simulate
*/

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left, *right;
        TreeNode(int _v):val(_v),left(NULL),right(NULL){}
    };
    
    TreeNode* UpsideDownBinaryTree2(TreeNode *root) {// recursive
        if(root->left!=NULL) {
            TreeNode* ret=UpsideDownBinaryTree(root->left);
            root->left->left=root->right;
            root->left->right=root;
            root->left=NULL;
            root->right=NULL;
            return ret;
        }
        else return root;
    }
    
    TreeNode* UpsideDownBinaryTree3(TreeNode *root) { //non-recursive, with stack
        if(root==NULL) return root;
        if(root->left==NULL) return root;
        stack<TreeNode*> st;
        TreeNode* ret=NULL;
        
        while(root->left!=NULL||!st.empty()) {
            if(root->left!=NULL) {
                st.push(root);
                root=root->left;
            }
            else {
                if (ret==NULL) ret=root;
                
                root=st.top();
                st.pop();
                
                root->left->left=root->right;
                root->left->right=root;
                root->left=NULL;
                root->right=NULL;
            }
        }
        
        return ret;
    }
    
    TreeNode* UpsideDownBinaryTree(TreeNode *root) { //non-recursive, no stack
        if(root==NULL) return root;
        TreeNode *cur=root, *parent=NULL, *left=NULL, *right=NULL;
        while(cur!=NULL) {
            left=cur->left;
            cur->left=right;
            right=cur->right;
            cur->right=parent;
            parent=cur;
            cur=left;
        }
        return parent;
    }
    
    static void visit(TreeNode *root) {
        if(root==NULL) {
            cout<<"NULL"<<",";
            return;
        }
        else cout<<root->val<<",";
        visit(root->left);
        visit(root->right);
    }
    
    static void test() {
        int n, id, x, lc, rc;
        cin>>n;
        vector<TreeNode*> edge;
        Solution sol;
        for(int i=0;i<n;i++)
            edge.push_back(new TreeNode(-1));
        for(int i=0;i<n;i++) {
            cin>>id>>x>>lc>>rc;
            TreeNode *cp=edge[id];
            cp->val=x;
            if(lc!=-1) cp->left=edge[lc];
            if(rc!=-1) cp->right=edge[rc];
        }
        cout<<"visit before:"<<endl;
        visit(edge[0]);
        cout<<endl;
        cout<<"visit after:"<<endl;
        visit(sol.UpsideDownBinaryTree(edge[0]));
        cout<<endl;
    }
};
