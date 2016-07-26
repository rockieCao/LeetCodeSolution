#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> dp(num + 1);
		dp[0] = 0;
		for (int i = 1; i <= num; ++i) {
			if (i & 1) dp[i] = dp[i / 2] + 1;
			else dp[i] = dp[i / 2];
		}
		return dp;
	}

	static void test() {
		Solution sol;
		int n;
		while (cin >> n) {
			vector<int> res=sol.countBits(n);
			for (int i = 0; i < res.size(); ++i)
				cout << res[i] << ",";
			cout << endl;
		}
	}
};