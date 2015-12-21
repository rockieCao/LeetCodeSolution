#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* Problem: 3 Sum Smaller
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
For example, given nums = [-2, 0, 1, 3], and target = 2.
Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]

Solution: similar as k-sum problem. O(n^2) sort and two-pointers
**/

class Solution {
public:
    int threeSumSmaller(vector<int> nums, int target) {
        int n=nums.size();
        if(n<3) return 0;
        
        int ans=0;
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; ++i) {
            int left=i+1, right=n-1;
            while(left<right) {
                if(nums[i]+nums[left]+nums[right]>=target) --right;
                else {
                    ans+=right-left;
                    ++left;   
                }
            }
        }
        
        return ans;
    }
    
    static void test() {
        int n,target;
        Solution sol;
        
        while(cin>>n>>target) {
            vector<int> nums(n);
            for(int i=0;i<n;i++) cin>>nums[i];
            cout<<"ans="<<sol.threeSumSmaller(nums, target)<<endl;
        }
    }
};
