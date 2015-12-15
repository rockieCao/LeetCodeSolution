#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int sz = nums.size();
		vector<vector<int>> ret;
		if (sz == 0) return ret;
		sort(nums.begin(), nums.end());
		int upper = (1<<sz);
		for (int i = 0; i < upper; i++)
		{
			vector<int> tmp;
			for (int j = 0; j < sz; j++)
			{
				if ((i&(1<<j)))
				{
					tmp.push_back(nums[j]);
				}
			}
			ret.push_back(tmp);
		}

		return ret;
    }
};