#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 *Say you have an array for which the ith element is the price of a given stock on day i.
 *Design an algorithm to find the maximum profit. You may complete at most k transactions.
 *Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 *Solution: DP O(kN)
 *1、设j天完成不超过i次交易能得到的最大收益是f(i,j), 显然f(0,0) = 0,f(i, 1) = 0 因为只有1天不能完成任何交易
 *2、对最后一天也就是第j天发生的情况进行分类.第j天可能没有买卖,也可能最后一次卖出手里的股票,即
 *   f(i, j) = max{ f(i-1, j), f(i, j-1), f(i-1,k-1) + a[j] - a[k] },其中k >= 1 && k < j,即最后一天卖出的股票可能是第1天、第2天......第j-1天买入的股票
 *3、状态方程有了,似乎可以直接写了,但由于k的存在,这一算法的复杂度是O(k*n*n)的，在大数据情况下会TLE.我们看看能不能对后面这个f(i-1,k-1) + a[j] - a[k]做一些分析
 *4、我们令g(i, j) = f(i-1, k-1) - a[k],其中k >= 1 && k < j,那它表示什么意思呢,即最后第j天之前,最多进行了i-1次交易且最后一次买入发生在第k天,这一过程之后手里money最多还有多少或最少还欠多少.
 *   显然g(i, 1) = 0因为第1天之前最多进行0次交易g(i, 2) = f(i-1, 0) - a[1]将k带入,我们可以看到:
 *   g(i, j) = max{ f(i-1, 0) - a[1], f(i-1, 1) - a[2], ..., f(i-1, j-2) - a[j-1] }
 *   g(i, j+1) = max{ f(i-1, 0) - a[1], f(i-1, 1) - a[2], ..., f(i-1, j-2) - a[j-1], f(i-1, j-1) - a[j] }
 *             = max{ g(i, j), f(i-1, j-1) - a[j] }
 *   即g(i, j)的递推会用到f(i, j)的状态
 *5、将g(i, j)带入我们的状态方程，则 
 *   g(i, j) = max{ g(i, j-1), f(i-1, j-2) - a[j-1] }
 *   f(i, j) = max{  f(i-1, j), f(i, j-1), g(i, j) + a[j] }
 *   可以看到g的当前状态仅和本层前一个状态、f的上一层前一个状态有关,故用一个变量即可表示
 *   f当前状态仅和上一层的当前状态、本层的前一个状态、g的当前状态有关.因此我们可以采用滚动数组的形式,仅保留2层状态,即能完成状态转移的过程
 *6、优化:由于sz天最多进行sz/2次操作,所以当K>sz/2时,直接使用贪心算法即可O(N)
 **/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int sz = prices.size();
		if (sz <= 1) return 0;
		if (k >= sz-1) return noLimitMaxProfit(prices, sz);

		int* dp[2];
		dp[0] = new int[sz]; // dp[times][day]
		dp[1] = new int[sz];
		int g; // g[day] in practice

		memset(dp[0], 0, sz*sizeof(int));
		int cur = 1;
		for (int i = 0; i < k; i++)
		{
			dp[cur][0] = 0;
			dp[cur][1] = max(0, prices[1]-prices[0]);
			g = -prices[0];
			for (int j = 2; j < sz; j++)
			{
				g = max(g, dp[1-cur][j-2]-prices[j-1]);
				dp[cur][j] = max(max(dp[1-cur][j], dp[cur][j-1]), g+prices[j]);
			}

			cur = 1-cur;
		}

		return dp[1-cur][sz-1];
    }

	int noLimitMaxProfit(vector<int>& prices, int sz) { // gready algo
		int ans = 0;
		for (int i = 0; i < sz-1; i++)
		{
			if (prices[i+1]>prices[i]) ans+=prices[i+1]-prices[i];
		}
		return ans;
	}

	static void test() {
		int n, k, x;
		vector<int> vec;
		cin>>n>>k;
		for (int i = 0; i < n; i++) {
			cin>>x;
			vec.push_back(x);
		}
		Solution sol;
		cout<<sol.maxProfit(k, vec)<<endl;
	}

};