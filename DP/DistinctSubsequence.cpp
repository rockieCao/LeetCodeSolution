#include<iostream>
#include<vector>
#include<string>
using namespace std;

/* Distinct Subsequences
 * DP. can use rolling array to optimize memory
 * dp[i][j] represent how many T[1..j] appears in S[1..i]
 * then dp[i][j] = { dp[i-1][j-1] if S[i]==T[j], 0 else} + dp[i-1][j];
 */
class Solution {
public:
    int numDistinct(string s, string t) { // using rolling array
        int slen = s.length();
        int tlen = t.length();
        if (slen==0 || tlen==0) return 0;
        vector<vector<int> > dp(2, vector<int>(tlen+1,0));
        int cur = 0, pre = 1;
        dp[cur][0] = 1;
        for (int i = 1; i <= slen; ++i) {
            cur = pre;
            pre = 1-pre;
            dp[cur][0] = 1; //initialize!!!
            for (int j = 1; j <= tlen && j <= i; ++j) {
                if (s[i-1]==t[j-1]) {
                    dp[cur][j] = dp[pre][j-1]+dp[pre][j];
                }
                else {
                    dp[cur][j] = dp[pre][j];   
                }
            }   
        }
        return dp[cur][tlen];
    }
    
    int numDistinct2(string s, string t) { //original dp
        int slen = s.length();
        int tlen = t.length();
        if (slen==0 || tlen==0) return 0;
        vector<vector<int> > dp(slen+1, vector<int>(tlen+1,0));
        dp[0][0] = 1;
        for (int i = 1; i <= slen; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= tlen && j <= i; ++j) {
                if (s[i-1]==t[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];   
                }
            }   
        }
        return dp[slen][tlen];
    }
};
