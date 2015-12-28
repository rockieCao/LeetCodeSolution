#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int slen = word1.length();
        int tlen = word2.length();
        if (slen==0) return tlen;
        if (tlen==0) return slen;
        
        vector<vector<int> > dp(2,vector<int>(tlen+1,tlen+slen));
        int cur=0, pre=1;
        dp[cur][0] = 0;
        for(int j=1;j<=tlen;j++) {
            dp[cur][j] = j;   
        }
        for(int i=1;i<=slen;i++) {
            cur=pre;
            pre=1-pre;
            dp[cur][0] = i;
            for(int j=1;j<=tlen;j++) {
                if(word1[i-1]==word2[j-1])
                    dp[cur][j]=dp[pre][j-1];
                else
                    dp[cur][j]=1+min(dp[pre][j-1],min(dp[pre][j],dp[cur][j-1]));
            }   
        }
        return dp[cur][tlen];
    }
    
    int minDistance2(string word1, string word2) {
        int slen = word1.length();
        int tlen = word2.length();
        if (slen==0) return tlen;
        if (tlen==0) return slen;
        
        vector<vector<int> > dp(slen+1,vector<int>(tlen+1,tlen+slen));
        dp[0][0] = 0; //initialize !!!
        for(int i=1;i<=slen;i++) {
            dp[i][0] = i;   
        }
        for(int j=1;j<=tlen;j++) {
            dp[0][j] = j;   
        }
        for(int i=1;i<=slen;i++) {
            for(int j=1;j<=tlen;j++) {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }   
        }
        return dp[slen][tlen];
    }
};
