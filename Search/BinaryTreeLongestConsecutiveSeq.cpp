#include <iostream>
#include <vector>
using namespace std;

/*Problem:
Binary Tree Longest Consecutive Sequence

Total Accepted:  437 Total Submissions:  1351 Difficulty: Medium 

Given a binary tree, find the length of the longest consecutive sequence path.
The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,

   1
    \
     3
    / \
   2   4
        \
         5

Longest consecutive sequence path is 3-4-5, so return 3.
    2
    \
     3
    / 
   2    
  / 
 1

Longest consecutive sequence path is 2-3,not3-2-1, so return 2. 

Solution: DFS O(n)
*/

class Solution {
public:
    struct TreeNode{
        int val;
        TreeNode *left, *right;
        TreeNode(int x):val(x),left(NULL),right(NULL){}    
    };
    
    int maxL;
    
    int longestConsecutive(TreeNode* root) {
        if (root==NULL) return 0;
        maxL=1;
        search(root);
        return maxL;
    }
    
    int search(TreeNode* cp) {
        if(cp->left==NULL&&cp->right==NULL) {
            return 1;    
        }
        int len=1;
        if(cp->left!=NULL) {
            int childL=search(cp->left);
            if(cp->val+1==cp->left->val)
                ++childL;
            len=max(len,childL);
        }
        if(cp->right!=NULL) {
            int childL=search(cp->right);
            if(cp->val+1==cp->right->val)
                ++childL;
            len=max(len,childL);    
        }
        maxL=max(maxL,len);
        return len;
    }
    
    static TreeNode* buildTree(vector<vector<int>> &edge, vector<int> &val, int cur) {
        TreeNode* p=new TreeNode(val[cur]);    
        if(edge[cur].size()==0) return p;
        if(edge[cur][0]!=-1) p->left=buildTree(edge, val, edge[cur][0]);
        if(edge[cur][1]!=-1) p->right=buildTree(edge, val, edge[cur][1]);
        return p;
    }
    
    static void test() {
        int n;
        Solution sol;
        while(cin>>n) {
            int x,num,left,right;
            vector<vector<int>> edge(n,vector<int>());
            vector<int> val(n);
            for(int i=0;i<n;++i) {
                cin>>x>>num>>left>>right;
                edge[x].push_back(left);
                edge[x].push_back(right);
                val[x]=num;
            }
            TreeNode *root=buildTree(edge,val,0);
            cout<<"ans="<<sol.longestConsecutive(root)<<endl;
        }
    }
    
};

