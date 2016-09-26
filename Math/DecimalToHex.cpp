#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
	char* hex = "0123456789abcdef";

	string toHex(int num) {
		if (num == 0) return "0";

		string res = "";
		unsigned int x = (unsigned int)num;
		while(x!=0) {
			res = hex[x & 15] + res;
			x >>= 4; //>>为有符号右移，预先强制转换为无符号类型，实现无符号右移操作
		}

		return res;
	}
};