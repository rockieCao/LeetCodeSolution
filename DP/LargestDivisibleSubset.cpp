#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int n = nums.size(), ans = -1;
		vector<int> dp(n), pre(n);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; ++i) {
			dp[i] = 1;
			pre[i] = -1;
			for (int j = i-1; j >= 0; --j) {
				if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					pre[i] = j;
				}
			}
			if (ans == -1 || dp[i] > dp[ans]) ans = i;
		}
		cout << ans << endl;
		vector<int> res;
		int x = ans;
		while (x != -1) {
			res.push_back(nums[x]);
			x = pre[x];
		}

		return res;
	}

	static void test() {
		int n, x;
		vector<int> nums;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			nums.push_back(x);
		}
		vector<int> res = Solution().largestDivisibleSubset(nums);
		cout << "ans=";
		for each(int i in res){
			cout << i << ",";
		}
		cout << endl;
	}
};