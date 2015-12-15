#include <iostream>
#include <vector>
using namespace std;

// To find element appears more than [n/3]
// Solution: O(N)
// 2 passes. First pass to get the 2 highest frequent elements
//           Second pass to get the count of each element and check if cnt>size/3.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int sz = nums.size();
		vector<int> ret;
		if (sz == 0) return ret;

		int x[2], cnt[2]={0};
		for (int i = 0; i < sz; i++) {
			if (cnt[0] == 0 || x[0] == nums[i])
			{
				x[0] = nums[i];
				cnt[0]++;
			}
			else if (cnt[1] == 0 || x[1] == nums[i])
			{
				x[1] = nums[i];
				cnt[1]++;
			}
			else 
			{
				cnt[0]--;
				cnt[1]--;
			}
		}

		cnt[0] = 0; cnt[1] = 0;
		for (int i = 0; i < sz; i++)
		{
			if (nums[i] == x[0]) cnt[0]++;
			else if (nums[i] == x[1]) cnt[1]++;
		}

		if (cnt[0] > sz/3) ret.push_back(x[0]);
		if (cnt[1] > sz/3) ret.push_back(x[1]);

		return ret;
    }

	static void test()
	{
		int n,x;
		vector<int> vec;
		cin>>n;
		for (int i = 0; i < n; i++)
		{
			cin>>x;
			vec.push_back(x);
		}
		Solution sol;
		vector<int> ret = sol.majorityElement(vec);
		for (int i = 0; i < ret.size(); i++)
			cout<<ret[i]<<endl;
	}
};