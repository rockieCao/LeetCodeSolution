#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
		if (sz <= 1) return 0;

		int ans = 0;
		for (int i = 0; i < sz-1; i++)
		{
			if (prices[i+1]<=prices[i]) continue;
			ans += prices[i+1]-prices[i];
		}

		return ans;
    }
};