#include <iostream>
#include <vector>
using namespace std;

/*Problem:

You are given a m x n 2D grid initialized with these three possible values.
1.
-1 - A wall or an obstacle.

2.
0 - A gate.

3.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647. Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.


For example, given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF 

After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

Solution: DFS OR BFS
*/

class Solution {  
public:
    int n,m;
    void wallsAndGates(vector<vector<int>> &rooms) {//need to use & here to modify the grid in-place
        n=rooms.size();
        if(n==0) return;
        m=rooms[0].size();
        if(m==0) return;
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(rooms[i][j]==INT_MAX) rooms[i][j]=search(rooms,visited,i,j);
            }
        }
    }
    
    int search(vector<vector<int>> &rooms, vector<vector<bool>> &visited, int i, int j) {
        if(i<0||i>=n||j<0||j>=m||rooms[i][j]==-1) return INT_MAX;
        if(rooms[i][j]==0) return 0;
        if(visited[i][j]) return rooms[i][j]; //visit 数组记录当前遍历痕迹 
        if(rooms[i][j]>0&&rooms[i][j]<INT_MAX) return rooms[i][j]; //rooms[i][j]可能在前面已经找到最小距离，即使此时visited[i][j]==false 
        
        visited[i][j]=true;
        int up=search(rooms, visited, i-1, j);
        int down=search(rooms, visited, i+1, j);
        int left=search(rooms, visited, i, j-1);
        int right=search(rooms, visited, i, j+1);
        
        visited[i][j]=false;
        int mmin=min(up,min(down,min(left,right)));
        
        return mmin==INT_MAX?mmin:mmin+1;
    }
    
    static void test() {
        Solution sol;
        int n,m;
        while(cin>>n>>m) {
            vector<vector<int>> rooms(n,vector<int>(m,0));
            for(int i=0;i<n;++i) {
                for(int j=0;j<m;++j) {
                    cin>>rooms[i][j];    
                }
            }
            sol.wallsAndGates(rooms);
            cout<<"ans="<<endl;
            for(int i=0;i<n;++i) {
                for(int j=0;j<m;++j) {
                    cout<<" "<<rooms[i][j];
                }
                cout<<endl;
            }
        }
    }
};
