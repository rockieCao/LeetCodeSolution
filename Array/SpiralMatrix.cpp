#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
        int m = matrix.size();
		if (m == 0) return ret;
		int n = matrix[0].size();
		if (n == 0) return ret;

		int dir[4][2] = {0,1,1,0,0,-1,-1,0};
		int d = 0, x = 0, y = 0, bordleft=0, bordright=n-1, bordup=0, borddown=m-1;
		ret.push_back(matrix[0][0]);
		for (int i = m*n-2; i>=0; i--)
		{
			int xx = x+dir[d][0], yy=y+dir[d][1];
			while (xx<bordup||xx>borddown||yy<bordleft||yy>bordright) {
				d=(d+1)%4;
				switch (d){
					case 1: bordup++; break;
					case 2: bordright--; break;
					case 3: borddown--; break;
					case 0: bordleft++; break;
				}
				xx = x+dir[d][0], yy=y+dir[d][1];
			}			
			ret.push_back(matrix[xx][yy]);
			x = xx, y = yy;
		}
		return ret;
    }
};