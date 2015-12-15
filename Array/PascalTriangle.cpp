#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
		if (numRows == 0) return ret;

		ret.push_back(vector<int>(1,1));
		if (numRows == 1) return ret;
		ret.push_back(vector<int>(2));
		ret[1][0]=1;
		ret[1][1]=1;
		for (int i = 2; i < numRows; i++)
		{
			vector<int> tmp;
			tmp.push_back(1);
			for (int j = 1; j < i; j++)
				tmp.push_back(ret[i-1][j-1]+ret[i-1][j]);
			tmp.push_back(1);
			ret.push_back(tmp);
		}

		return ret;
    }
};