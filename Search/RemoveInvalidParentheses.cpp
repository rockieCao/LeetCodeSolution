#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
#include<vector>
#include<cmath>
using namespace std;

//DFS or BFS

class Solution {
public:
    int best;
    
    vector<string> removeInvalidParentheses(string s) {//DFS, faster but more complex
        vector<string> ret;
        int n = s.length(), left=0, right=0;    
        unordered_map<string,bool> mp, dupmp;
        for(int i=0;i<n;++i) {
            if(s[i]=='(') left++;
            else if(s[i]==')') right++;    
        }
        best=0;
        dfs(0,left,right,s,ret,mp, dupmp);
        if(ret.empty()) { //special handle: the worse case is to remove all parentheses but left non-parentheses
          string tmp="";
          for(int i=0;i<n;++i)
            if(s[i]!='('&&s[i]!=')') tmp+=s[i];
          ret.push_back(tmp);
        }
        return ret;
    }
    
    void dfs(int ith, int left, int right, string &s, vector<string> &ret, unordered_map<string,bool> &mp, unordered_map<string,bool> &dupmp) {
        //cout<<"debug:"<<left<<","<<right<<","<<s<<endl;
        if(dupmp.find(s)!=dupmp.end()) return; //note: this prune is important
        dupmp[s]=true;
        int n=s.length();
        if(left==right) {
            if(isValid(s)) {
                //cout<<"debug:"<<s<<endl;
                if(n>=best) {
                    if(n>best) {
                        best=n;
                        ret.clear();
                        mp.clear();
                    }
                    if(mp.find(s)==mp.end()) {
                        mp[s]=true;
                        ret.push_back(s);
                    }
                }
                return;
            }
        }
        if(n<best) return;
        //int delta=abs(left-right);
        for(int i=ith;i<n;++i) {
            if(s[i]!='('&&s[i]!=')') continue;
            string cur=s.substr(0,i)+s.substr(i+1);
            if(s[i]=='(') --left;
            else if(s[i]==')') --right;
            //if(abs(left-right)<delta) { //this prune is incorrect
                dfs(i,left, right, cur, ret, mp, dupmp);
            //}
            if(s[i]=='(') ++left;
            else if(s[i]==')') ++right;
        }
    }
    
    vector<string> removeInvalidParentheses2(string s) {//BFS
        vector<string> ret;
        int n=s.length();
        queue<string> que;
        unordered_map<string,bool> mp;
        
        que.push(s);
        mp[s]=true;
        bool found=false;
        while(!que.empty()) {
            s=que.front(); que.pop();
            if (isValid(s)) {
                found=true;
                ret.push_back(s);
            }
            if(found) continue; //once found, need to drop more element
            
            for(int i=0;i<s.length();++i) {
                if(s[i]!='('&&s[i]!=')') continue;
                string t=s.substr(0,i)+s.substr(i+1); //drop 1 element each time based on current root
                if (mp.find(t)==mp.end()) {
                    que.push(t);
                    mp[t]=true;
                }
            }
        }
        
        return ret;
    }
    
    bool isValid(string s) {
        int cnt=0;
        for(int i=0;i<s.length();++i) {
            if(s[i]=='(') ++cnt;
            else if(s[i]==')') { 
                if(cnt==0) return false;
                --cnt;
            }
        }
        return cnt==0;
    }
    
    static void test() {
        string str;
        Solution sol;
        while(cin>>str) {
            vector<string> ret=sol.removeInvalidParentheses(str);
            for(auto a:ret) {
                cout<<a<<",";    
            }
            cout<<endl;
        }
    }
};
