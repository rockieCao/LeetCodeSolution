#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		int n = nums.size()-1;

		if (n < 1) return ;

		while (n>0&&nums[n-1]>=nums[n])
		{
			--n;
		}

		if (n == 0) // already in descending order, just revert the vec
		{
			for (int i = 0, j = nums.size()-1; i < j; ++i,--j)
			{
				swap(nums[i],nums[j]);
			}
		}
		else
		{
			int nextElem = nums.size()-1;
			while (nextElem>=n&&nums[nextElem]<=nums[n-1])
			{
				--nextElem;
			}
			swap(nums[n-1], nums[nextElem]);

			sort(nums.begin()+n, nums.end());
		}
    }

	static void test() {
		int n,x;
		cin>>n;
		vector<int> nums;
		for (int i = 0 ; i < n ; i++)
		{
			cin>>x;
			nums.push_back(x);
		}
		Solution sol;
		sol.nextPermutation(nums);
		cout<<"Result:";
		for (int elem : nums)
			cout<<elem<<",";
		cout<<endl;
	}
};