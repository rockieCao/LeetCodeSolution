#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	int rob(TreeNode* root) {
		if (!root) return 0;
		unordered_map<TreeNode*, int> record;
		
		return dfs(root, record);
	}

	int dfs(TreeNode* root, unordered_map<TreeNode*, int> &record) {
		if (!root)
			return 0;
		if (record.count(root))
			return record[root];
		int val = 0;
		if (root->left)
		{
			val += dfs(root->left->left, record) + dfs(root->left->right, record);
		}
		if (root->right)
		{
			val += dfs(root->right->left, record) + dfs(root->right->right, record);
		}
		val = max(val + root->val, dfs(root->left, record) + dfs(root->right, record));
		record[root] = val;
		return val;
	}

	int rob2(TreeNode* root) {
		if (!root) return 0;
		vector<int> res = dfs2(root);
		return max(res[0], res[1]);
	}

	vector<int> dfs2(TreeNode* root) { //当前结点为根的子树能得到的最大值 返回2维结果(取/不取当前结点)
		if (!root) return vector<int>(2, 0);
		vector<int> left = dfs2(root->left);
		vector<int> right = dfs2(root->right);
		vector<int> res(2, 0);
		res[0] = max(left[0], left[1]) + max(right[0], right[1]);
		res[1] = left[0] + right[0] + root->val;
		return res;
	}
};