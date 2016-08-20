#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		int len = s.length();
		for (int i = 0, j = len - 1; i < j;)
		{
			if (isVowel(s[i]) && isVowel(s[j])) {
				swap(s[i], s[j]);
				++i;
				--j;
			}
			else if (isVowel(s[i]))
				--j;
			else if (isVowel(s[j]))
				++i;
			else {
				++i;
				--j;
			}
		}
		return s;
	}

	bool isVowel(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
			|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	}
};