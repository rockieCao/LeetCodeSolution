#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		if (n==0) return vector<vector<int>>();
        vector<vector<int> > ret(n);
		for (int i = 0; i < n; i++)
		{
			vector<int> tmp(n, 0);
			ret[i] = tmp;
		}

		int dir[4][2] = {0,1,1,0,0,-1,-1,0};
		int d = 0, x = 0, y = 0, bordleft=0, bordright=n-1, bordup=0, borddown=n-1;
		ret[0][0] = 1;
		int nn = n*n;
		for (int i = 2; i<=nn; i++)
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
			ret[xx][yy]=i;
			x = xx, y = yy;
		}

		return ret;
    }
};