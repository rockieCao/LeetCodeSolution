#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();

		vector<int> ret(sz, 1);
		for (int i = sz-2; i>=0; i--)
			ret[i]=ret[i+1]*nums[i+1];

		int prevProd = 1;
		for (int i = 0; i < sz; i++)
		{
			ret[i]=prevProd*ret[i];
			prevProd*=nums[i];
		}

		return ret;
    }
};