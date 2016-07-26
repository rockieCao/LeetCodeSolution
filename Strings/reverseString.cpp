#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
public:
	static string reverseString(string s) {
		if (s.length() <= 1) return s;

		for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
			char ch = s[i];
			s[i] = s[j];
			s[j] = ch;
		}

		return s;
	}

	static void test() {
		string s;
		while (cin >> s)
		{
			cout << "out:" << reverseString(s) << endl;
		}
	}
};