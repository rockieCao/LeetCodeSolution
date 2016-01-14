#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<cmath>
using namespace std;

class Solution {
public:
    int n;
    
    bool wordBreak(string s, unordered_set<string>& wordDict) { //dp
        n = s.length();
        if (wordDict.find(s)!=wordDict.end()) return true;
        vector<bool> dp(n+1,false);
        int minL=INT_MAX,maxL=INT_MIN;
        for (auto &word: wordDict) {
            minL=min(minL,(int)word.length());
            maxL=max(maxL,(int)word.length());    
        }
        for(int i=0; i<n; ++i) 
            if(dp[i]) {
                for(int len=minL;i+len<=n&&len<=maxL;++len) {
                    if(wordDict.find(s.substr(i, len))!=wordDict.end())
                        dp[i+len]=true;
                }
            }
        return dp[n];
    }
    
    bool wordBreak2(string s, unordered_set<string>& wordDict) { //bfs
        n=s.length();
        if (wordDict.find(s)!=wordDict.end()) return true;
        vector<vector<int>> reach(n,vector<int>());
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                if(wordDict.find(s.substr(i,j-i+1))!=wordDict.end()) reach[i].push_back(j);
            }
        }
        unordered_set<int> edge[2];
        
        int cur=0, pre=1;
        for(int i:reach[0]) 
            edge[cur].insert(i);
        for(int i=0; i<n; ++i)
        {
            pre=cur;
            cur=1-cur;
            edge[cur].clear();
            for(int j: edge[pre]) {
                for(int k: reach[j+1]) {
                    if(edge[pre].find(k)!=edge[pre].end()) continue;
                    edge[cur].insert(k);    
                    if(k==n-1) return true;
                }
            }
        }
        
        return false;
    }
    
    static void test() {
        string str,s;
        Solution sol;
        while(cin>>str) {
            int m;
            unordered_set<string> dict;
            cin>>m;
            for(int i=0;i<m;++i) {
                cin>>s;
                dict.insert(s);
            }
            cout<<"ret="<<sol.wordBreak(str,dict)<<endl;
        }
    }
};
