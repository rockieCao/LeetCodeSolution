#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
		if (sz <= 1) return 0;

		int mmin = prices[0];
		int ans = 0;
		for (int i = 1; i < sz; i++)
		{
			if (prices[i]-mmin>ans)
				ans = prices[i]-mmin;
			if (prices[i]<mmin)
				mmin = prices[i];
		}

		return ans;
    }
};