#include <iostream>
#include <string>
using namespace std;

//Similiar problem: Single Number

class Solution {
public:
	char findTheDifference(string s, string t) {
		int slen = s.length(), tlen = t.length();
		char res = 0;
		for (int i = 0; i < slen; ++i)
			res ^= s[i];
		for (int i = 0; i < tlen; ++i)
			res ^= t[i];
		return res;
	}
};