#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int sz = nums.size();
		if (sz <= 1) return sz; // case: [3 3 3 2 5] should return 3
		
		bool start = true; //to skip identical elements in the begining
		int gap = 0;
		int maxL = 1;
		int lastNum = 0;
		for (int i = 1; i < sz; ++i) {
			if ((start && (nums[i]!=nums[i-1])) || gap*(nums[i] - nums[i - 1]) < 0) {
				lastNum = nums[i];
				gap = nums[i] - nums[i - 1];
				maxL++;
				start = false;
			}
			else
				continue;
		}

		return maxL;
	}

	int wiggleMaxLength2(vector<int>& nums) {
		int sz = nums.size();
		if (sz <= 1) return sz; // case: [0,0] should return 1
		vector<int> dp[2];
		for (int i = 0; i < sz; ++i) {
			dp[0].push_back(1); //pos
			dp[1].push_back(1); //neg
		}

		int res = 1;
		for (int i = 1; i < sz; ++i) {
			for (int j = 0; j < i; ++i) {
				if (nums[i]<nums[j] && dp[0][j] + 1>dp[1][i])
					dp[1][i] = dp[0][j] + 1;
				if (nums[i]>nums[j] && dp[1][j] + 1>dp[0][i])
					dp[0][i] = dp[1][j] + 1;
			}
			if (res < dp[0][i]) res = dp[0][i];
			if (res < dp[1][i]) res = dp[1][i];
		}

		return res;
	}
};
