#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*Problem: Two Sum III - Data structure design
Design and implement a TwoSum class. It should support the following operations:add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,

add(1); add(3); add(5);
find(4) -> true
find(7) -> false

Solution: hash-table: add O(1), find O(n)
          BST with double links: add O(logN), find O(n)
*/

class TwoSum { // BST with double links
private:
    struct TreeNode{
        int val,cnt;
        TreeNode *left, *right, *pre, *next;
        TreeNode(int _v, int _c):val(_v),cnt(_c),left(NULL),right(NULL),pre(NULL),next(NULL){ }
    };
    
    TreeNode* root;
    TreeNode* head;
    TreeNode* tail;
    
    void insertInTree(int val) {
        TreeNode *p=root;
        TreeNode *pre=NULL, *next=NULL;
        while(true) {
            if(val>(p->val)) {
                pre=p;
                if(p->right!=NULL) p=p->right;
                else {
                    p->right=new TreeNode(val,1);
                    insertInDList(p->right,pre,next);
                    break;
                }
            }
            else if(val<(p->val)) {
                next=p;
                if(p->left!=NULL) p=p->left;
                else {
                    p->left=new TreeNode(val,1);
                    insertInDList(p->left,pre,next);
                    break;
                }
            }
            else {
                ++(p->cnt);
                break;
            }
        }
    }
    
    void insertInDList(TreeNode *p, TreeNode *pre, TreeNode *next) {
        if(pre!=NULL)
            pre->next=p;
        else
            head = p;
        if(next!=NULL)
            next->pre=p;
        else
            tail=p;
        p->pre=pre;
        p->next=next;   
    }
public:
    TwoSum() {
        root=head=tail=NULL;   
    }
    
    void add(int number) {
        if(root==NULL) {
            root=new TreeNode(number,1);
            head = tail = root;
        }
        else
            insertInTree(number);
    }
    
    bool find(int value) { // two-pointers
        if(head!=NULL&&tail!=NULL&&head!=tail) {
            TreeNode* left=head, *right=tail;
            while(left!=right) {
                if((left->val)*2==value&&(left->cnt)>1) return true;
                if((right->val)*2==value&&(right->cnt)>1) return true;
                int sum=(left->val)+(right->val);
                if(sum>value)
                    right=right->pre;
                else if(sum<value)
                    left=left->next;
                else return true;
            }
        }
        return false;
    }
};

class TwoSum2 {
private:
    unordered_map<int,int> mp;
public:
    void add(int number) { // O(1)
        if(mp.find(number)==mp.end())
            mp[number]=1;
        else
            mp[number]++;
    }
    
    bool find(int value) { // O(N)
        for(auto p:mp) {
            int other=value-(p.first);
            if(other==(p.first)&&(p.second)>1) return true;
            else if(other!=(p.first)&&mp.find(other)!=mp.end()) return true;
        }
        
        return false;
    }
};

class Solution {
public:    
    static void test() {
        string cmd;
        int x;
        TwoSum obj;
        while(cin>>cmd) {
            if(cmd=="q") break;
            if(cmd=="a") {
                cin>>x;
                obj.add(x);   
            }
            else if(cmd=="f") {
                cin>>x;
                cout<<"ans="<<obj.find(x)<<endl;
            }
        }
    }
};

