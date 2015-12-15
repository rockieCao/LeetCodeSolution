#include <iostream>
#include <vector>
using namespace std;

// Similar solution as "JumpGame"
class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
		if (sz == 0) return 0;

		int steps = 0, globalMax = 0, lastMax = 0;
		for (int i = 0; i < sz; i++)
		{
			if (i>lastMax)
			{
				++steps;
				lastMax = globalMax;
				if (lastMax < i) return -1; //can't reach
			}
			globalMax = max(globalMax, i+nums[i]);
		}

		return steps;
    }
};