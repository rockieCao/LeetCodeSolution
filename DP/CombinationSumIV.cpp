#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> cn;

	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target+1, 0);
		dp[0]=1;
		sort(nums.begin(), nums.end());
		for (int i = 1; i <= target; i++)
		{
			for (int x : nums) {
				if (x > i) break;
				dp[i] += dp[i - x];
			}
		}
		return dp[target];
	}

	int combinationSum4_2(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		cn.push_back(1);
		for (int i = 1; i <= target; ++i)
			cn.push_back(cn.back()*i);

		int res = 0;
		vector<pair<int, int> > path;
		dfs2(nums, 0, target, res, path);
		return res;
	}

	void dfs2(vector<int> &nums, int ith, int left, int &res, vector<pair<int,int> >& path) { //RunTime Error: stack overflow
		//cout << ith << "," << left << endl;
		if (left < 0) return;
		if (left == 0) {
			//cout << "path ";
			
			long long tmp = 1LL;
			long long sum = 0;
			for (auto it : path) {
				sum += it.second;
			}
			tmp *= cn[sum];
			for (auto it : path) {
				sum /= cn[it.second];
			}

			res += sum;
			return;
		}
		if (ith >= nums.size()) return;
		if (left < nums[ith]) return;
		dfs2(nums, ith + 1, left, res, path);
		int sum = left;
		for (int i = 1; sum >= nums[ith]; ++i) {
			path.push_back(pair<int, int>(nums[ith], i));
			sum -= nums[ith];
			dfs2(nums, ith + 1, sum, res, path);
			path.pop_back();
		}
	}

	static void test() {
		Solution sol;
		int x, n, target;
		while (cin >> n >> target) {
			vector<int> nums;
			for (int i = 0; i < n; ++i) {
				cin >> x;
				nums.push_back(x);
			}
			cout << "res=" << sol.combinationSum4(nums, target) << endl;
		}
	}
};