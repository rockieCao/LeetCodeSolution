#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// test case: [0,1,1,2,2]
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
		if (n==0) return 1;
		sort(nums.begin(), nums.end());
		int j = 1;
		for (int i = 0; i < n; i++)
		{
			if (nums[i]<=0) continue;
			else if (nums[i]==j) ++j;
			else if (nums[i]>j) break;
		}
		return j;
    }
};