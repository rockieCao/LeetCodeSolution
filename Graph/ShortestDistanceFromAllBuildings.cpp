#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*Problem: Shortest Distance From All Buildings
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
1)Each 0 marks an empty land which you can pass by freely.
2)Each 1 marks a building which you cannot pass through.
3)Each 2 marks an obstacle which you cannot pass through.

For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):
1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.

Solution: BFS from each building and record distance sum on each empty land. Also need to check whether current empty land can reach all builds.
          O(kMN) where k is #empty
Test Case:
3 5
1 0 2 0 1
0 0 0 0 0
0 0 1 0 0
*/

class Solution {
public:
    vector<vector<int>> dist;
    vector<vector<int>> destCnt;
    
    int shortestDistance(vector<vector<int>> grid) {
        int n=grid.size();
        if(n==0) return -1;
        int m=grid[0].size();
        if(m==0) return -1;
        
        int building=0;
        dist = vector<vector<int>>(n,vector<int>(m,0));
        destCnt = vector<vector<int>>(n,vector<int>(m,0));
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j) {
                if(grid[i][j]==1) {
                    ++building;
                    bfs(grid, i, j, n, m);
                }
            }
        
        int ans=INT_MAX;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j) {
                if(grid[i][j]==0&&destCnt[i][j]==building&&dist[i][j]<ans) {
                    ans=dist[i][j];
                }
            }
        return ans;
    }
    
    void bfs(vector<vector<int>>& grid, int x0, int y0, int n, int m) {
        int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<bool>> visited(n,vector<bool>(m, false));
        visited[x0][y0]=true;
        int len=0;
        queue<pair<int,int>> que;
        que.push(pair<int,int>(x0,y0));
        while(!que.empty()) {
            ++len;
            int sz=que.size();
            for(int k=0;k<sz;++k) {
                int x=que.front().first, y=que.front().second;
                que.pop();
                
                for(int i=0;i<4;++i) {
                    int xx=x+dir[i][0], yy=y+dir[i][1];
                    if(xx>=0&&xx<n&&yy>=0&&yy<m&&grid[xx][yy]==0&&!visited[xx][yy]) {
                        dist[xx][yy]+=len;
                        destCnt[xx][yy]++;
                        visited[xx][yy]=true;
                        que.push(pair<int,int>(xx,yy));
                    }
                }
            }
        }
    }
    
    static void test() {
        int n,m;
        Solution sol;
        while(cin>>n>>m) {
            vector<vector<int>> grid(n,vector<int>(m,0));
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j) {
                    cin>>grid[i][j];
                }
            cout<<"ans="<<sol.shortestDistance(grid)<<endl;
        }
    }
};
