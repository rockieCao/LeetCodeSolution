#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        else if (sz == 1) return nums[0];
        else if (sz == 2) return max(nums[0],nums[1]);
        int ans = 0, dp[3] = {nums[0], max(nums[0],nums[1]), 0};
        for (int i = 2; i < sz; i++) {
            dp[2] = max(dp[1], dp[0]+nums[i]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};
