#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//�ݹ��㷨������[��ջ������]��ջ
//�ǵݹ��㷨��
//  ����stack��һ����¼���֣�һ����¼��ǰδ������ַ���
//  ����[����ջ���ֱ��¼���ֺ�֮ǰδ������ַ���
//  ����]����ջ��ǰ����������δ������ַ��������ظ�����append����һ��δ������ַ�������
//  ע�⴦���������������numStack.empty()==true

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
		string curStr = ""; //��ǰδ������ַ���
		for (int i = 0; i < slen; ++i) {
			if (s[i] >= '0' && s[i] <= '9') {
				cnt = cnt * 10 + (s[i] - '0');
			}
			else if (s[i] == '[') {
				numStack.push(cnt); //��¼����
				cnt = 0;

				strStack.push(curStr); //��ǰδ������ַ�����ջ
				curStr = "";
			}
			else if (s[i] >= 'a' && s[i] <= 'z') {
				if (!numStack.empty()) { //������������Ƕ��
					curStr += s[i];
				}
				else
					res+=s[i]; 
			}
			else if (s[i] == ']') {
				int num = numStack.top();
				numStack.pop();

				if (numStack.empty()) { //����������Ƕ��
					for (int j = 0; j < num; ++j)
						res.append(curStr); //ֱ��append��ǰ���ַ����������
					curStr = strStack.top();
					strStack.pop();
				}
				else {
					string tmp = "";
					for (int j = 0; j < num; ++j)
						tmp.append(curStr);
					curStr = strStack.top() + tmp; //�ϴ�δ������ַ���+��ǰ������ַ���
					strStack.pop();
				}
			}
		}

		return res;
	}
};
