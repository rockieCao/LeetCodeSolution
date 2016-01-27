#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    struct TreeLinkNode {
        int val;
        TreeLinkNode *left, *right, *next;
        TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
    };

    void connect2(TreeLinkNode *root) { // bfs
        if (root==NULL) return ;
        queue<TreeLinkNode*> que;
        que.push(root);
        int count = 1;
        TreeLinkNode* curLevelNxt = NULL;
        while (!que.empty())
        {
            TreeLinkNode *cur = que.front();
            que.pop();
            --count;

            if (curLevelNxt == NULL) curLevelNxt = cur;
            else { curLevelNxt->next=cur; curLevelNxt=cur; }

            if (cur->left!=NULL) {
                que.push(cur->left);
            }
            if (cur->right!=NULL) {
                que.push(cur->right);
            }
            
            if (count==0)
            {
                count = que.size();
                curLevelNxt = NULL;
            }
        }
    }

    void connect(TreeLinkNode *root) { // dfs: record the end next pointer in each depth
        if (root==NULL) return ;
        vector<TreeLinkNode*> nxt;
        search(root, 0, nxt);
    }

    void search(TreeLinkNode *cur, int depth, vector<TreeLinkNode*> &nxt) {
        if (cur==NULL) return;
        if (cur->left!=NULL)
        {
            if (nxt.size()>depth)
            {
                nxt[depth]->next = cur->left;
                nxt[depth]=cur->left;
            }
            else
            {
                nxt.push_back(cur->left);
            }
            search(cur->left, depth+1, nxt);
        }
        if (cur->right!=NULL)
        {
            if (nxt.size()>depth)
            {
                nxt[depth]->next = cur->right;
                nxt[depth]=cur->right;
            }
            else
            {
                nxt.push_back(cur->right);
            }
            search(cur->right, depth+1, nxt);
        }
    }
};