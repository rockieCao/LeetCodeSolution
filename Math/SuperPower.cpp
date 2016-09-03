#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
One knowledge: ab % k = (a%k)(b%k)%k
Since the power here is an array, we'd better handle it digit by digit.
One observation:
a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (((a^123456) % k) ^ 10 ) % k * a^7 % k
Looks complicated? Let me put it other way:
Suppose f(a, b) calculates a^b % k; Then translate above formula to using f :
f(a,1234567) = f(a, 1234560) * f(a, 7) % k = f(f(a, 123456),10) * f(a,7)%k;
*/

class Solution {
public:
	const int base = 1337;

	int superPow(int a, vector<int>& b) {
		if (b.empty()) return 1;
		int last_digit = b.back();
		b.pop_back();
		return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
	}

	int powmod(int a, int b) { // a^b mod base
		int ret = 1;
		int x = a % base;
		while (b != 0) {
			if ((b & 1) == 1) {
				ret = ret * x % base;
			}
			x = x*x%base;
			b >>= 1;
		}
		return ret;
	}
};
