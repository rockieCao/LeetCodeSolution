#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int sq = (int)sqrt(n);
        if (sq*sq == n) return 1;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        for (int i = 2; i <=n; i++) {
            sq = (int)sqrt(i);
            if (sq*sq==i) { dp[i]=1; continue; }
            dp[i] = INT_MAX;
            for (int j = 1; j <= sq; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+1);   
            }
        }
        return dp[n];
    }
};
