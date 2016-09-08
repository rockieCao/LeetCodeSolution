#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//递归算法：遇到[进栈，遇到]出栈
//非递归算法：
//  两个stack，一个记录数字，一个记录当前未解码的字符串
//  遇到[，进栈，分别记录数字和之前未解码的字符串
//  遇到]，出栈当前计数，并将未解码的字符串进行重复，在append到上一个未解码的字符串后面
//  注意处理最外层的情况，即numStack.empty()==true

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
		
		stack<int> numStack;
		stack<string> strStack;

		string res = "";
		int cnt = 0;
		string curStr = ""; //当前未解码的字符串
		for (int i = 0; i < slen; ++i) {
			if (s[i] >= '0' && s[i] <= '9') {
				cnt = cnt * 10 + (s[i] - '0');
			}
			else if (s[i] == '[') {
				numStack.push(cnt); //记录计数
				cnt = 0;

				strStack.push(curStr); //当前未解码的字符串进栈
				curStr = "";
			}
			else if (s[i] >= 'a' && s[i] <= 'z') {
				if (!numStack.empty()) { //如果不是最外层嵌套
					curStr += s[i];
				}
				else
					res+=s[i]; 
			}
			else if (s[i] == ']') {
				int num = numStack.top();
				numStack.pop();

				if (numStack.empty()) { //如果是最外层嵌套
					for (int j = 0; j < num; ++j)
						res.append(curStr); //直接append当前的字符串到结果中
					curStr = strStack.top();
					strStack.pop();
				}
				else {
					string tmp = "";
					for (int j = 0; j < num; ++j)
						tmp.append(curStr);
					curStr = strStack.top() + tmp; //上次未解码的字符串+当前解码的字符串
					strStack.pop();
				}
			}
		}

		return res;
	}
};
