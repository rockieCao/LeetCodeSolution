#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
		if (sz == 0) return 0;

		int sum = 0, ans = nums[0], start = -1, end = -1, ansStart = -1, ansEnd = -1;
		for(int i = 0; i < sz; i++)
		{
			if (sum+nums[i]>0)
			{
				if (start == -1) start = i;
				sum+=nums[i];
				end = i;

				if (sum > ans)
				{
					ans = sum;
					ansStart = start;
					ansEnd = end;
				}
			}
			else {
				sum = 0;
				start = -1;
				end = -1;
			}
			if (nums[i] > ans) // Note: if every element in the array is negative
			{
				ans = nums[i];
				ansStart = i;
				ansEnd = i;
			}
		}

		return ans;
    }

	static void test()
	{
		int n, x;
		vector<int> vec;
		cin>>n;
		for (int i = 0; i < n; i++)
		{
			cin>>x;
			vec.push_back(x);
		}
		Solution sol;
		cout<<"ans="<<sol.maxSubArray(vec)<<endl;
	}
};
