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
			x >>= 4; //>>Ϊ�з������ƣ�Ԥ��ǿ��ת��Ϊ�޷������ͣ�ʵ���޷������Ʋ���
		}

		return res;
	}
};