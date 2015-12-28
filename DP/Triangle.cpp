#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        if (row == 0) return 0;
        int col = triangle[row-1].size();
        vector<int> dp[2];
        dp[0] = vector<int>(col);
        dp[1] = vector<int>(col);
        int cur = 1, pre=0, ans = INT_MAX;
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < row; i++)
        {
            dp[cur][0] = dp[pre][0]+triangle[i][0];
            for (int j = 1; j < col; j++)
            {
                dp[cur][j] = min(dp[pre][j], dp[pre][j-1])+triangle[i][j];
            }
            cur = 1-cur;
            pre = 1-pre;
        }

        for (int j = 0; j < col; j++)
            if (ans > dp[pre][j]) ans = dp[pre][j];

        return ans;
    }
};