#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/* Problem: Largest BST SubTree

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7


The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.

Solution: Divide and conquer (bottom up). O(N)

*/

struct TreeNode {
    int val;
    TreeNode *lc,*rc;
    TreeNode(int x):val(x),lc(NULL),rc(NULL){}
};

class Solution {
public:
    struct Node {
        bool isBST;
        int mmin, mmax, size;
        Node() {
            isBST=false;
            mmin = INT_MAX;
            mmax = INT_MIN;
            size = 0;
        }
    };
    
    int largestBSTSubTree(TreeNode *root) {
        int ret=0;
        dfs(root, ret);
        return ret;
    }
    
    Node* dfs(TreeNode* root, int &ret) {
        Node *cur = new Node();
        if (root==NULL) {
            cur->isBST = true;
            return cur;
        }
        Node *left = dfs(root->lc, ret);
        Node *right = dfs(root->rc, ret);
        if (left->isBST&&root->val>left->mmax&&right->isBST&&root->val<right->mmin) {
            cur->isBST = true;
            cur->mmin = min(root->val, left->mmin);
            cur->mmax = max(root->val, right->mmax);
            cur->size = left->size+right->size+1;
            if(cur->size>ret)
                ret=cur->size;
        }
        return cur;
    }
    
    static TreeNode* buildTree() {
        int n,id,val,lc,rc;
        cin>>n;
        TreeNode *root = NULL;
        unordered_map<int,TreeNode*> mp;
        for(int i=0;i<n;++i) {
            cin>>id>>val>>lc>>rc;
            TreeNode *cur;
            if (mp.find(id)==mp.end()) {
                cur=new TreeNode(val);
                mp[id]=cur;
            }
            else cur=mp[id];
            mp[id]->val=val;
            if(lc!=-1) {
                TreeNode *lcptr;
                if (mp.find(lc)==mp.end()) {
                    lcptr=new TreeNode(-1);
                    mp[lc]=lcptr;
                }
                else lcptr=mp[lc];
                mp[id]->lc=lcptr;
            }
            if(rc!=-1) {
                TreeNode *rcptr;
                if (mp.find(rc)==mp.end()) {
                    rcptr=new TreeNode(-1);
                    mp[rc]=rcptr;
                }
                else rcptr=mp[rc];
                mp[id]->rc=rcptr;
            }
            if(root==NULL) root=cur;
        }
        return root;
    }
    
    static void visitTree(TreeNode* root) {
        if(root==NULL) return;
        cout<<root->val<<",";
        visitTree(root->lc);
        visitTree(root->rc);
    }
    
    static void test() {
        TreeNode *root=buildTree();
        visitTree(root);
        Solution sol;
        cout<<"ans="<<sol.largestBSTSubTree(root)<<endl;    
    }
};
