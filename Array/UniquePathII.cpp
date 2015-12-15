#include <iostream>
#include <vector>
using namespace std;

// dynamic program
// dp[i][j] = (obstacleGrid[i][j]==0)?C[i-1][j]+C[i][j-1]:0
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
		if (row == 0) return 0;
		int col = obstacleGrid[0].size();
		if (col == 0) return 0;

		vector<vector<int> > C(row);
		for (int i = 0; i < row; i++)
		{
			vector<int> tmp(col);
			C[i] = tmp;
		}

		C[0][0] = (obstacleGrid[0][0]==0)?1:0;
		for (int i = 1; i < row; i++)
			C[i][0] = (obstacleGrid[i][0]==0)?C[i-1][0]:0;
		for (int j = 1; j < col; j++)
			C[0][j] = (obstacleGrid[0][j]==0)?C[0][j-1]:0;
		for (int i = 1; i < row; i++)
			for (int j =1; j < col; j++)
			{
				C[i][j] = (obstacleGrid[i][j]==0)?(C[i-1][j]+C[i][j-1]):0;
			}
		return C[row-1][col-1];
    }

};