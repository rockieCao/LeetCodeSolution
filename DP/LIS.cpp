#include <iostream>
#include <vector>
using namespace std;

/* Longest increasing subsequence
 * O(nlogn)
 * dp[L] represents the mimum tail if the increasing sequence is of length L
 * for a new value X, try to find bigest L so that X>dp[L-1]&&X<=dp[L] using binary search
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n<=1) return n;
        
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        int len = 1;
        for (int i=1; i<n; ++i) {
            if (nums[i]>dp[len]) dp[++len]=nums[i];
            else dp[binsearch(dp, nums[i], len)] = nums[i];   
        }
        return len;
    }
    
    int binsearch(vector<int>& dp, int x, int k) {
        if (x < dp[1]) return 1;
        int left = 1, right = k, mid;
        while (right-left>1) {
            mid=(left+right)/2;
            if (dp[mid]>x) {
                right = mid;   
            }   
            else
                left = mid;
        }
        return dp[right-1]<x?right:right-1; //important check
    }
};
