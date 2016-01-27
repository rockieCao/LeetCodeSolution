#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;

        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j]=='0') continue;
                bloodfill(grid, i, j, n, m);
                cnt++;
            }
        return cnt;
    }

    void bloodfill(vector<vector<char>>& grid, int x, int y, int n, int m) {
        grid[x][y] = '0';
        int dir[4][2] = {-1,0,0,1,1,0,0,-1};
        for (int i = 0; i < 4; i++)
        {
            int xx = x+dir[i][0], yy = y + dir[i][1];
            if (xx>=0&&xx<n&&yy>=0&&yy<m&&grid[xx][yy]=='1')
                bloodfill(grid, xx, yy, n, m);
        }
    }
};