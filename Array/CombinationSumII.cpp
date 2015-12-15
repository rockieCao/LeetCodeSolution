#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sz = candidates.size();
		vector<vector<int>> ret;
		if (sz == 0) return ret;

		int sum = 0, mmin = candidates[0];
		map<int,int> cnt;
		vector<int> nums;
		for (int elem : candidates)
		{
			sum += elem;
			if (elem < mmin) mmin = elem;
			if (cnt.find(elem)==cnt.end())
			{
				cnt[elem]=1;
				nums.push_back(elem);
			}
			else
				cnt[elem]++;
		}

		if (target < mmin || target > sum) return ret;

		sort(nums.begin(),nums.end());
		sz = nums.size();
		search(0, sz, nums, cnt, target, vector<int>(), ret);

		return ret;
    }

	void search(int start, int end, vector<int>& nums, map<int,int>& cnt, int target, vector<int> path, vector<vector<int>>& ret)
	{
		if (target == 0)
		{
			ret.push_back(path);
			return;
		}

		if (start >= end || target < nums[start]) return;
		/*int sum = 0;
		for (int i = start; i < end; i++)
			sum += nums[i]*cnt[nums[i]];
		if (target > sum) return;*/  // <-- this optimization takes more time than it tried to reduce

		search(start+1, end, nums, cnt, target, path, ret);
		int repeat = cnt[nums[start]];
		for (int i = 1; i <= repeat; i++)
		{
			path.push_back(nums[start]);
			search(start+1, end, nums, cnt, target-i*nums[start], path, ret);
		}
		for (int i = 1; i <= repeat; i++)
			path.pop_back();

	}
};
