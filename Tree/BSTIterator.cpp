#include <iostream>
#include <vector>
using namespace std;

// Morris inorder traversal
class BSTIterator {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    TreeNode* cur;
    TreeNode* pre;
    BSTIterator(TreeNode *root) {
        cur = root;
        pre = NULL;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur != NULL;
    }

    /** @return the next smallest number */
    int next() {
        int ret = -1;
        while (cur) {
            if (cur->left == NULL){
                ret = cur->val;
                cur = cur->right;
                break;
            }
            else {
                pre = cur->left;
                while (pre->right!=NULL&&pre->right!=cur)
                    pre = pre->right;
                if (pre->right==NULL) {
                    pre->right = cur;
                    cur = cur->left;
                }
                else {
                    pre->right = NULL;
                    ret = cur->val;
                    cur = cur->right;
                    break;
                }
            }
        }
        return ret;
    }
};
