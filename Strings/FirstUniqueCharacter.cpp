#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		int cnt[26] = { 0 }, idx[26] = { 0 };
		int slen = s.length();
		for (int i = 0; i < slen; ++i) {
			int j = s[i] - 'a';
			cnt[j]++;
			if (cnt[j] == 1) idx[j] = i;
		}

		int res = slen;
		for (int i = 0; i < 26; ++i)
			if (cnt[i] == 1)
				res = min(res, idx[i]);
		return res==slen?-1:res;
	}
};