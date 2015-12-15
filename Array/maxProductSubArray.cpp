#include <iostream>
#include <vector>
using namespace std;;

/*
similar like Maximum Subarray question

difference is the max value could be get from 3 situations

current maxValue * A[i]  if A[i]>0

current minValue * A[i]  if A[i]<0
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
		if (n<1) return 0;

		int ans = nums[0];
		int mmax = nums[0], mmin=nums[0];
		for (int i = 1; i < n; i++)
		{
			int tmp = mmin*nums[i];
			int tmp2 = mmax*nums[i];
			mmax = max(nums[i], max(tmp, tmp2));
			mmin = min(nums[i], min(tmp, tmp2));
			ans = max(mmax, ans);
		}

		return ans;
    }
};