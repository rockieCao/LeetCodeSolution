#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        else if (n==1) return nums[0];
        else if (n==2) return max(nums[0],nums[1]);
        int ans = max(max(nums[0],nums[1]),nums[2]); //note: initialize ans for n==3 case
        //1.suppose last house won't be selected
        int dp[3]={nums[0], max(nums[0],nums[1]), 0};
        for (int i = 2; i < n-1; i++) {
            dp[2] = max(dp[1], dp[0]+nums[i]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        ans = max(ans,dp[2]);
        //2.suppose last house can be selected i.e. skip 1st house
        dp[0]=0; dp[1]=nums[1];
        for (int i = 2; i <n; i++) {
            dp[2] = max(dp[1], dp[0]+nums[i]);
            dp[0] = dp[1];
            dp[1] = dp[2];   
        }
        ans = max(ans, dp[2]);
        return ans;
    }
};
