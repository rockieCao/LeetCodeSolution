#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        if(n<=1) return 0;
        
        vector<vector<bool> > valid(n,vector<bool>(n,false)); //valid[i][j]表示s[i..j]是否为回文串 
        for(int i=0;i<n;++i) valid[i][i]=true;
        for(int l=2;l<=n;++l) {
            for(int i=0;i+l-1<n;++i)
            {
                if(s[i]==s[i+l-1]&&(l==2||valid[i+1][i+l-2]))
                    valid[i][i+l-1]=true;
            }
        }
        
        vector<int> dp(n,0); //dp[i]表示s[0..i]最少切几段，每段均为回文 
        dp[0]=0;
        for(int j=1;j<n;++j) {
            dp[j]=j;
            if(valid[0][j]) { dp[j]=0; continue; }
            for(int l=1;l<=j;++l) {
                if(valid[j-l+1][j]) {
                    if(dp[j-l]+1<dp[j]) dp[j]=dp[j-l]+1;
                }
            }   
        }
        return dp[n-1];
    }
};
