#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// DP
// dp[beg][end]表示[beg, end]区间中所需要付出的最小的最大代价是多少
// 状态转移方程是：dp[beg][end] = min(dp[beg][end], x+max(dp[beg][x-1],dp[x+1][end]) for x in [beg, end])

class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));
		
		for (int i = 1; i <= n; ++i)
			dp[i][i] = i;
		for (int len = 2; len <= n; ++len)
		{
			for (int i = 1; i + len - 1 <= n; ++i) {
				dp[i][i + len - 1] = INT_MAX;
				for (int x = i; x <= i + len - 1; ++x) { //O(N*N*N)
					dp[i][i + len - 1] = min(dp[i][i+len-1], max(dp[i][x-1], dp[x+1][i+len-1])); //note: here the begin and end index may be n+1 in boundary case
				}
			}
		}

		return dp[1][n];
	}

	int getMoneyAmount2(int n) {
		vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
		return payForRange(dp, 1, n);
	}

	int payForRange(vector<vector<int> > dp, int start, int end) { //may cause stack overflow if n is large
		if (start >= end)
			return 0;
		if (dp[start][end] != 0)
			return dp[start][end];

		int minPay = INT_MAX;
		for (int x = start; x <= end; ++x) {
			// calc the amount to pay if pick x.
			int pay = x + max(payForRange(dp, start, x - 1), payForRange(dp, x + 1, end));
			minPay = min(minPay, pay);
		}

		dp[start][end] = minPay;
		return minPay;
	}
};