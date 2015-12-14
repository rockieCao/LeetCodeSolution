#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> st;//O(logN) to get lower_bound,upper_bound
        int n=nums.size();
        for(int i=0; i<n; ++i) {
            if(st.size()==k+1) {
                st.erase(st.find(nums[i-k-1]));
            }
            auto it=st.lower_bound(nums[i]-t); //note: nums[i]-t may be out of int, use long long to avoid it
            if(it!=st.end()&&(*it-nums[i])<=t)
                return true;
            st.insert(nums[i]);
        }
        return false;
    }
};
