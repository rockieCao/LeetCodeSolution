#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		int low = 1, high = num, mid;
		while (low <= high) {
			mid = low + (high - low) / 2;
			long long t = (long long)mid*mid;
			if (t== num) return true;
			if (t > num) high = mid - 1;
			else low = mid + 1;
		}

		return false;
	}

	static void test() {
		Solution sol;
		int x;
		while (cin >> x) {
			cout << "res=" << sol.isPerfectSquare(x) << endl;
		}
	}
};