#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
		return num > 0 && !(num&(num - 1)) && (num - 1) % 3 == 0;
	}

	bool isPowerOfFour4(int num) { //2的power 并且1只出现在奇数位
		return num > 0 && !(num&(num - 1)) && (num & 0x55555555) == num;
	}

	bool isPowerOfFour3(int num) { //log4(num)为整数=>log(num)/log(4)-（int)(log(num)/log(4))==0
		return num > 0 && int(log10(num) / log10(4)) - log10(num) / log10(4) == 0;
	}

	bool isPowerOfFour2(int num) {
		if (num == 1) return true;
		else if (num == 0 || num % 4 > 0) return false;
		else return isPowerOfFour2(num / 4);
	}
};