#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int pre1=1,pre2=2,cur;
        for (int i = 3; i <=n; i++) {
            cur=pre1+pre2;
            pre1=pre2;
            pre2=cur;
        }
        return cur;
    }
    
    int climbStairs2(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <=n; i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
