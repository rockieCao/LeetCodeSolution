#include <iostream>
#include <string>
#include <vector>
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
		TreeNode *left, *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL) return 0;
		else return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
	}

	int sumOfLeftLeaves(TreeNode* root, bool isLeftChild) {
		if (root == NULL) return 0;
		if (root->left == NULL && root->right == NULL) return isLeftChild?(root->val):0;
		int cur = 0;
		if (root->left != NULL)
			cur += sumOfLeftLeaves(root->left, true);
		if (root->right != NULL)
			cur += sumOfLeftLeaves(root->right, false);
		return cur;
	}

};