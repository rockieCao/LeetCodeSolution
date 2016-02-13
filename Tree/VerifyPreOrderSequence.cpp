#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up: Could you do it using only constant space complexity?*/

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
    };

    bool verifyPreorder(vector<int>& preorder) { // recursive version
        int n = preorder.size();
        if (n <= 2) return true;
        else return verify(preorder, 0, n-1);
    }

    bool verify(vector<int>& preorder, int s, int t) { // time: O(N), space: O(N)
        if (s >= t) return true;
        int root = preorder[s], index = -1;
        for (int i = s+1; i <= t; i++) {
            if (preorder[i]>root) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = index+1; i<=t; i++) {
                if (preorder[i]<=root) {
                    return false;
                }
            }
            return verify(preorder, s+1, index-1)&&verify(preorder, index, t);
        }
        else { //only left subtree
            return verify(preorder, s+1, t);
        }
    }

    bool verifyPreorder2(vector<int>& preorder) { // time: O(N), space: O(N)
        int n  = preorder.size();
        if (n<=2) return true;
        bool ret = true;
        int lower = -1;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (lower > -1 && preorder[i] < lower) { //meet a value smaller than root while we just pop whole left subtree, so it is false
                ret = false;
                break;
            }
            while (!st.empty() && st.top()<preorder[i]) { //when meet a value bigger than root->left, then pop whole left subtree which shares same root with new node, lower : current root
                lower = st.top();
                st.pop();
            }
            st.push(preorder[i]); //insert element in subtree of root->left (initially, we treat root as first left child of virtual tree)
        }
        return ret;
    }

    static void test() {
        int n,x;
        cin>>n;
        vector<int> preorder;
        for(int i=0; i<n; i++) {
            cin>>x;
            preorder.push_back(x);
        }
        cout<<"result:"<<Solution().verifyPreorder2(preorder)<<endl;
    }
};
