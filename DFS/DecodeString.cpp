#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	string DFS(string s, int &k)
	{
		string ans;
		int cnt = 0;
		while (k < s.size())
		{
			if (isdigit(s[k])) cnt = cnt * 10 + (s[k++] - '0');
			else if (s[k] == '[')
			{
				string tem = DFS(s, ++k);
				for (int i = 0; i < cnt; i++) ans += tem;
				cnt = 0;
			}
			else if (s[k] == ']')
			{
				k++;
				return ans;
			}
			else ans += s[k++];
		}
		return ans;
	}

	string decodeString(string s) {
		int k = 0;
		return DFS(s, k);
	}

	string decodeString2(string s) {
		int slen = s.length();
		
		stack<int> st1;
		stack<string> st2;

		int cnt = 0;
		for (int i = 0; i < slen; ) {
			if (s[i] >= '0' && s[i] <= '9') {
				cnt = cnt * 10 + (s[i] - '0');
				++i;
			}
			else if (s[i] == '[') {
				st1.push(cnt);
				cnt = 0;

				st2.push("[");
				++i; //skip [
				string str = "";
				while (i<slen && s[i]>='a' && s[i]<='z') {
					str += s[i];
					++i;
				}
				st2.push(str);
			}
			else if (s[i] == ']') {
				++i;
				string str = "";
				while (!st2.empty() && st2.top() != "[") {
					int k = st1.top();
					st1.pop();
					for (int j = 0; j < k; ++j)
						str += st2.top();
					st2.pop();
				}
				if (!st2.empty()) st2.pop();
				st2.push(str);
				st1.push(1);
			}
		}

		return st2.top();
	}
};
