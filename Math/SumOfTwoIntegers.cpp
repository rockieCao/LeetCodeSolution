#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		if (a == 0) return b;
		if (b == 0) return a;
		if (a == -b) return 0;

		while (b) {
			int carry = (a&b) << 1;
			a = a^b;
			b = carry;
		}

		return a;
	}

	static void test() {
		Solution sol;
		int a, b;
		while (cin >> a >> b) {
			cout << "sum=" << sol.getSum(a, b) << endl;
		}
	}
};
