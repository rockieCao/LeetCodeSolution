#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0) return 1;
		if (n > 10) n = 10;
		int res = 10;
		vector<int> cnt(11, 0); //9^2 * 8 * ... * (9-k+2)
		for (int i = 2; i <= n; i++) {
			int tmp = 1;
			for (int j = 9; j >= 9 - i + 2; j--)
			{
				tmp *= j;
			}
			res += 9*tmp;
		}
		return res;
	}

	int countNumbersWithUniqueDigits2(int n) {
		if (n == 0) return 1;
		if (n > 10) n = 10;
		int res = 0;
		if (n >= 1) res += 10;

		vector<int> nn;
		nn.push_back(1);
		for (int i = 1; i <= n; i++)
		{
			nn.push_back(nn.back()*i);
		}
		vector<vector<int> > dp;
		dp.push_back(vector<int>(1024, 0));
		dp.push_back(vector<int>(1024, 0));

		for (int i = 0; i < 10; i++)
		{
			dp[0][1 << i] = 1;
		}
		int cur = 0, pre = 1;
		for (int i = 2; i <= n; i++)
		{
			cur = pre;
			pre = 1 - pre;
			for (int j = 0; j < 1024; j++)
				dp[cur][j] = 0;
			for (int j = 0; j < 1024; j++)
			{
				if (dp[pre][j] == 0) continue;
				for (int k = 0; k < 10; k++)
				{
					if ((j&(1 << k))||dp[cur][j|(1<<k)]==1) continue;
					dp[cur][j | (1 << k)] = 1;
					//printf("i=%d, j=%d, k=%d\n", i, j, k);
					res+=nn[i];
					if ((j | (1 << k)) & 1)
						res -= nn[i - 1];
				}
			}

		}
		return res;
	}

	static void test() {
		Solution sol;
		int n;
		while (cin >> n) {
			cout << "res=" << sol.countNumbersWithUniqueDigits(n) << endl;
		}
	}
};
