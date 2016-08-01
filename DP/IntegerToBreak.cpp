#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> record;

	int integerBreak(int n) { // skill: split 3 as many as possible and it can be proved
		record = vector<int>(59, 0);
		if (n == 2) return 1;
		else return dp(n, true);
	}

	int dp(int n, bool first)
	{
		if (!first)
		{
			if (n <= 4) return n;
			if (record[n] > 0) return record[n];
		}

		int up = n;
		if (first)
			up = n - 1;
		int res = -1;
		for (int i = 2; i <= up; i++)
		{
			int tmp = dp(n - i, false);
			if (tmp>0 && (res == -1 || res < i*tmp))
				res = i*tmp;
		}
		if (res>0) record[n] = res;
		return res;
	}

	static void test() {
		Solution sol;
		int n;
		while (cin >> n) {
			cout << "res=" << sol.integerBreak(n) << endl;
		}
	}
};
