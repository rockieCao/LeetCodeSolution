#include <iostream>
#include <vector>
using namespace std;

//dp[i][j]表示以i，j为右下角的最大正方形的边长 
class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int n = matrix.size();
        if (n==0) return 0;
        int m = matrix[0].size();
        if (m==0) return 0;
        
        int ans = 0;
        vector<vector<int> > dp(n, vector<int>(m,0));
        for (int i = 0; i <n; i++) {
            if (matrix[i][0]=='1') {
                dp[i][0]=1;   
                ans = 1;
            }   
        }
        for (int i = 0; i <m; i++) {
            if (matrix[0][i]=='1') {
                dp[0][i]=1;
                ans = 1;   
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j]=='1') {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]))+1;
                    if (dp[i][j]>ans) ans = dp[i][j];
                }   
            }   
        }
        return ans*ans;
    }
};
