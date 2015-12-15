#include <iostream>
#include <vector>
using namespace std;

// DP + 逆向思维
// Problem: given a grid, start from top left and go to bottom right. Each grid is a number (pos means gain, neg means loss). Before reach each grid,
//          the HP must be greater than 0. Find the lowest initial HP needed to reach the goal.
// 
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
		if (row == 0) return 0;
		int col = dungeon[0].size();
		if (col == 0) return 0;

		vector<vector<int> > dp(row);
		for(int i = 0; i < row; i++)
		{
			vector<int> tmp(col, -1);
			dp[i] = tmp;
		}

		dp[row-1][col-1] = (dungeon[row-1][col-1]>=0)?1:-dungeon[row-1][col-1]+1;
		for (int i = row-2; i>=0; i--) dp[i][col-1] = (dungeon[i][col-1]>=0)?((dp[i+1][col-1]-dungeon[i][col-1]<=0)?1:dp[i+1][col-1]-dungeon[i][col-1]):dp[i+1][col-1]-dungeon[i][col-1];
		for (int j = col-2; j>=0; j--) dp[row-1][j] = (dungeon[row-1][j]>=0)?((dp[row-1][j+1]-dungeon[row-1][j]<=0)?1:dp[row-1][j+1]-dungeon[row-1][j]):dp[row-1][j+1]-dungeon[row-1][j];

		for (int i = row-2; i>=0; i--)
			for (int j = col-2; j>=0; j--)
			{
				int a = (dp[i+1][j]-dungeon[i][j]<=0)?1:dp[i+1][j]-dungeon[i][j];
				int b = (dp[i][j+1]-dungeon[i][j]<=0)?1:dp[i][j+1]-dungeon[i][j];
				dp[i][j] = min(a,b);
			}

		return dp[0][0];
    }
};