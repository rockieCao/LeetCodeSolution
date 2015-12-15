#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size();
		vector<int> ret;
		if (sz == 0) return ret;

		int start = 0;
		while (digits[start]==0&&start<sz-1) //ignore leading zeros
			++start;
		int carry = 1;
		for (int i = sz-1; i >= start; i--)
		{
			ret.push_back(digits[i] + carry);
			if (ret[sz-1-i] > 9)
			{
				carry = 1;
				ret[sz-1-i] -= 10;
			}
			else
			{
				carry = 0;
			}
		}
		if (carry>0)
		{
			ret.push_back(carry);
		}

		reverse(ret.begin(), ret.end());

		return ret;
    }
};