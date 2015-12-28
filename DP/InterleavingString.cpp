#include <iostream>
#include <string>
#include <vector>
using namespace std;

// brute force O(2^Len3)
// DP O(Len1*Len2)
// dp[i][j]表示s3[0...i+j-1]可以由s1[0...i-1]与s2[0...j-1]交叉生成
// 则dp[i][j]=(dp[i-1][j]&&s1[i-1]==s3[i+j-1])||(dp[i][j-1]&&s2[j-1]==s3[i+j-1]) 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1len=s1.length();
        int s2len=s2.length();
        int s3len=s3.length();
        
        if (s3len!=s1len+s2len) return false;
        
        vector<vector<bool> > dp(s1len+1,vector<bool>(s2len+1,false));
        dp[0][0]=true;
        for(int i=1;i<=s1len;++i) {
            if(s3[i-1]==s1[i-1]) dp[i][0]=true;
            else break;
        }
        for(int i=1;i<=s2len;++i) {
            if(s3[i-1]==s2[i-1]) dp[0][i]=true;
            else break;   
        }
        for (int i=1;i<=s1len;++i) {
            for (int j=1;j<=s2len;++j) {
                if (dp[i-1][j]&&s1[i-1]==s3[i+j-1]) dp[i][j]=true;
                else if(dp[i][j-1]&&s2[j-1]==s3[i+j-1]) dp[i][j]=true;   
            }   
        }
        return dp[s1len][s2len];
    }
};
