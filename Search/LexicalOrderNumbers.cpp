#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> lexicalOrder(int n) { // simulate the rules: 1 10 11 12 13 2 3 ...
		vector<int> res(n);
		int cur = 1;
		for (int i = 0; i < n; ++i) {
			res[i] = cur;
			if (cur * 10 <= n)
				cur *= 10;
			else {
				if (cur >= n) cur /= 10;
				cur += 1;
				while (cur % 10 == 0) cur /= 10;
			}
		}
		return res;
	}

	vector<int> lexicalOrder2(int n) { // brute-force recursive way : very slow
		stringstream ss;
		string str;
		ss << n;
		ss >> str;
		vector<int> res;
		
		generateLexicalOrder(0, str.length() - 1, 0, res, n);

		return res;
	}

	void generateLexicalOrder(int ith, int end, int pre, vector<int> &res, const int n) {
		if (pre>0 && pre <= n)
			res.push_back(pre);
		if (ith > end) {
			return;
		}
		
		int maxN = 9;
		for (int i = ((ith == 0) ? 1 : 0); i <= maxN; ++i) {
			generateLexicalOrder(ith + 1, end, pre * 10 + i, res, n);
		}

	}

	static void test() {
		int n;
		Solution sol;
		while (cin >> n) {
			vector<int> res = sol.lexicalOrder(n);
			cout << "ans=";
			for (int i : res) {
				cout << i << ",";
			}
			cout << endl;
		}
	}
};
