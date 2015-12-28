#include <iostream>
#include <string>
#include <vector>
using namespace std;

//逆向思维
//首先分析踩最后一个气球的情况，假设踩C，那么获得的coid是nums[0]*nums[C]*nums[n+1]
//剩下的问题分解为求nums[0...C]和nums[C...n+1]两端中能获得的最大值 
//递归算法容易想到 

class Solution {
public:
    int maxCoins(vector<int>& nums) { // non-recursive DP
        int n = nums.size();
        if(n==0) return 0;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int len=1;len<=n;++len) {
            for(int i=1;i+len<=n+1;++i) {
                int j=i+len-1;
                for(int k=i;k<=j;++k) {
                    dp[i][j]=max(dp[i][j], dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]);
                }
            }
        }
        return dp[1][n];
    }
    
    int maxCoins2(vector<int>& nums) { // recursive algo
        int n=nums.size();
        if(n==0) return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        return search(nums, dp, 1, n);
    }
    
    int search(vector<int>& nums, vector<vector<int>>& dp, int start, int end) {
        if(start>end) return 0;
        if(dp[start][end]>0) return dp[start][end];
        int ret=0;
        for(int    i=start;i<=end;++i) {
            ret=max(ret, nums[start-1]*nums[i]*nums[end+1]
                        +search(nums, dp, start, i-1)
                        +search(nums, dp, i+1, end));    
        }
        dp[start][end]=ret;
        return ret;
    }
};
