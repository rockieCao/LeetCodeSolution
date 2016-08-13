#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int rlen = ransomNote.length(), mlen = magazine.length();
		if (rlen > mlen) return false;
		int cnt[26] = { 0 };
		for (int i = 0; i < mlen; ++i)
			cnt[magazine[i] - 'a']++;
		for (int i = 0; i < rlen; ++i) {
			char ch = ransomNote[i];
			if (cnt[ch - 'a'] <= 0) return false;
			cnt[ch - 'a']--;
		}

		return true;
	}
};

