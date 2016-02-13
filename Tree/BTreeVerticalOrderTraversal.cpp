#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*Problem: Binary Tree Vertical Order Traversal
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.

Examples:
 Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]


Solution: O(n)
  use a hash table to record the nodes on each vertical line (need to consider the traverse order)
  also need to record the min,max horizontal distance for final outputs

Test Cases:
5
0 3 1 2
1 9 -1 -1
2 20 3 4
3 15 -1 -1
4 7 -1 -1

7
0 3 1 2
1 9 3 4
2 20 5 6
3 4 -1 -1
4 5 -1 -1
5 2 -1 -1
6 7 -1 -1

*/

class Solution{
public:
    struct TreeNode{
        int val;
        TreeNode *lc, *rc;
        
        TreeNode(int _val):val(_val),lc(NULL),rc(NULL){}
    };
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==NULL) return ret;
        
        int mmin=0,mmax=0;
        unordered_map<int,vector<int>> mp;
        dfs(root,0,mmin,mmax,mp);
        
        for(int i=mmin; i<=mmax; ++i) {
            if(mp.find(i)!=mp.end()) {
                ret.push_back(vector<int>());
                for(auto val:mp[i]) {
                    ret.back().push_back(val);
                }
            }
        }
        
        return ret;
    }
    
    void dfs(TreeNode *root, int horizontalD, int &mmin, int &mmax, unordered_map<int,vector<int>> &mp) { // preOrder traverse: for each vertical line, top comes first; for each level, left comes first
        if(root==NULL) return;
        
        if(horizontalD<mmin) mmin=horizontalD;
        if(horizontalD>mmax) mmax=horizontalD;
        if(mp.find(horizontalD)==mp.end()) mp[horizontalD]=vector<int>();
        mp[horizontalD].push_back(root->val);
        
        if(root->lc!=NULL) dfs(root->lc, horizontalD-1, mmin, mmax, mp);
        if(root->rc!=NULL) dfs(root->rc, horizontalD+1, mmin, mmax, mp);
    }
    
    static void showTree(TreeNode *root) {
        if(root==NULL) {
            cout<<"null,";
            return;
        }
        cout<<root->val<<",";
        showTree(root->lc);
        showTree(root->rc);
    }
    
    static void test() {
        int n,x,val,left,right;
        Solution sol;
        while(cin>>n) {
            vector<TreeNode*> edge;
            for(int i=0;i<n;++i) {
                edge.push_back(new TreeNode(-1));
            }
            for(int i=0;i<n;++i) {
                cin>>x>>val>>left>>right;
                edge[x]->val=val;
                if(left!=-1) edge[x]->lc=edge[left];
                if(right!=-1) edge[x]->rc=edge[right];
            }
            showTree(edge[0]);
            cout<<endl;
            
            vector<vector<int>> ret=sol.verticalOrder(edge[0]);
            cout<<"ans=["<<endl;
            for(int i=0;i<ret.size();++i) {
                for(int j=0;j<ret[i].size();++j) {
                    cout<<ret[i][j]<<",";
                }
                cout<<endl;
            }
            cout<<"]"<<endl;
        }
    }
};
