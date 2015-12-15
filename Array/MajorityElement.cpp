#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
		if (sz == 0) return 0;

		int x = 0, cnt = 0;
		for (int i = 0; i < sz; i++)
		{
			if (cnt == 0)
			{
				x = nums[i];
				cnt = 1;
			}
			else if (nums[i]==x) ++cnt;
			else --cnt;
		}

		return x;
    }
};