#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret[2];

		ret[0].push_back(1);
		if (rowIndex == 0) return ret[0];
		ret[0].push_back(1);
		if (rowIndex == 1) return ret[0];

		int pre = 0, cur = 1;
		ret[0] = vector<int>(rowIndex+1);
		ret[0][0] = 1;
		ret[0][1] = 1;
		ret[1] = vector<int>(rowIndex+1);
		for (int i = 2; i <= rowIndex; i++)
		{
			ret[cur][0]=1;
			for (int j = 1; j < i; j++)
			{
				ret[cur][j] = ret[pre][j-1]+ret[pre][j];
			}
			ret[cur][i]=1;

			cur = 1-cur;
			pre = 1-pre;
		}

		return ret[pre];
    }
};