#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int cur, len;
    
    bool isValidSerialization(string preorder) {
        cur=0;
        len=preorder.length();
        return dfs(preorder)&&cur>=len;
    }
    
    bool dfs(string preorder) {
        if(cur>=len) return false;
        string str="";
        while(cur<len&&preorder[cur]!=',') {
            str+=preorder[cur];
            ++cur;
        }
        if(cur>=len&&str!="#") return false;
        if(str=="#") return true;
        ++cur;
        if(!dfs(preorder)) return false;
        ++cur;
        if(!dfs(preorder)) return false;
        return true;
    }
    
    bool isValidSerialization2(string preorder) {
        // number of sentinel nodes = number of non-sentinel nodes+1
        int count=0, i=0, len=preorder.length();
        while(i<len-1) {
            string str="";
            while(i<len&&preorder[i]!=',') {
                str+=preorder[i];
                ++i;
            }
            ++i;
            if(str!="#") ++count;
            else {
                --count;
                if(count<0) return false;
            }
        }
        return count==0&&preorder[i]=='#';
    }
    
    static void test() {
        string preorder;
        Solution sol;
        while(cin>>preorder) {
            cout<<"ans="<<sol.isValidSerialization2(preorder)<<endl;
        }
    }
};
