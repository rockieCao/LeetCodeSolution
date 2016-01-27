#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Tree DP
// 维护两种最大sum:maxSum是当前子树的最大PathSum； maxSumWith是以当前根节点为一端的最大PathSum
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    struct Record {
        int maxSum;
        int maxSumWith; //start from current node

        Record(): maxSum(INT_MIN),maxSumWith(INT_MIN){} //注意默认值的设置
        Record(int _maxSum, int _maxSumWith): maxSum(_maxSum),maxSumWith(_maxSumWith){}
    };

    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;

        return search(root).maxSum;
    }

    Record search(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
        {
            int maxSum = (root->val);
            int maxSumWith = (root->val);
            return Record(maxSum, maxSumWith);
        }

        Record leftRec, rightRec;
        if (root->left)
            leftRec = search(root->left);
        if (root->right)
            rightRec = search(root->right);
        int maxSumWith = (root->val);
        if (root->left) maxSumWith = max(maxSumWith, (root->val)+leftRec.maxSumWith);
        if (root->right) maxSumWith = max(maxSumWith, (root->val)+rightRec.maxSumWith);
        int maxSum = max(max(leftRec.maxSum, rightRec.maxSum), maxSumWith);
        if (root->left && root->right) maxSum = max(maxSum, (root->val)+leftRec.maxSumWith+rightRec.maxSumWith);

        return Record(maxSum, maxSumWith);
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
        cout<<"calc max path sum ..."<<endl;
        cout<<"result = "<<Solution().maxPathSum(root)<<endl;
    }
};