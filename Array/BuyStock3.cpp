#include <iostream>
#include <vector>
using namespace std;

/**
 *Say you have an array for which the ith element is the price of a given stock on day i.
 *Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *Note:You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 *Solution: DP O(N)
 *          mmin[i] means the minimum value within [0,i]
 *          mmax[j] means the maximum value within [j,n-1]
 *          dp[i] means the max profit can be got by 1 transaction in range [0,i] -- O(N)
 *          ans = max(dp[i]+mmax[i]-prices[i])
 **/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
		if (sz <= 1) return 0;

		int part1 = 0, ans = 0;
		int* mmax = new int[sz];
		mmax[sz-1] = prices[sz-1];
		for (int i = sz-2; i>=0; i--)
		{
			if (prices[i]>mmax[i+1]) mmax[i] = prices[i];
			else mmax[i]=mmax[i+1];
		}

		int mmin = prices[0];
		for (int i = 1; i < sz; i++)
		{
			if (prices[i]-mmin>part1)
				part1 = prices[i]-mmin;
			if (mmin>prices[i])
				mmin = prices[i];
			if (part1 > ans)
				ans = part1;
			if (i+1<sz)
			{
				int part2 = mmax[i+1]-prices[i+1];
				if (part1+part2>ans)
					ans = part1+part2;
			}
		}
		
		return ans;
    }
};