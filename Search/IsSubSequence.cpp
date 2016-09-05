#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// find whether s is a subsequence of t
// solution: create index for each char, and use binary search to find next matching position

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int slen = s.length(), tlen = t.length();
		if (slen > tlen) return false;
		if (slen == 0) return true;

		vector<int> index[26];
		for (int i = 0; i < tlen; ++i)
			index[t[i] - 'a'].push_back(i);

		int pos = -1;
		for (int i = 0; i < slen; ++i) {
			int cur = s[i] - 'a';
			if (index[cur].size() == 0 || index[cur].back() <= pos)
				return false;
			auto it = lower_bound(index[cur].begin(), index[cur].end(), pos + 1);
			if (it == index[cur].end()) {
				return false;
			}
			pos = *it;
			//cout<<i<<","<<s[i]<<","<<pos<<","<<*it<<endl;
		}
		return true;
	}
};
