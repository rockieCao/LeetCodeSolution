#include<iostream>
#include<vector>
using namespace std;

/*Problem: Longest Increasing Path in the Matrix
Memorize + DFS, O(n*m)
*/

class Solution {
public:
    vector<vector<int>> dir;
    int n,m;
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (dir.size()==0) {
            dir=vector<vector<int>>(4,vector<int>(2,0));
            dir[0][0]=-1; dir[0][1]=0;
            dir[1][0]=0; dir[1][1]=1;
            dir[2][0]=1; dir[2][1]=0;
            dir[3][0]=0; dir[3][1]=-1;
        }
        
        n=matrix.size();
        if(n==0) return 0;
        m=matrix[0].size();
        
        int ans=1;
        vector<vector<int>> len(n,vector<int>(m,-1));
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j) {
                if(len[i][j]>0) { 
                    if(len[i][j]>ans) ans=len[i][j]; 
                    continue;
                }
                dfs(i,j,matrix,len);
                if(len[i][j]>ans) ans=len[i][j];
            }
        return ans;
    }
    
    void dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& len) {
        if(len[x][y]>0) return;
        len[x][y]=1;
        for(int d=0;d<4;++d) {
            int xx=x+dir[d][0], yy=y+dir[d][1];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&matrix[xx][yy]>matrix[x][y]) {
                dfs(xx,yy,matrix,len);
                len[x][y]=max(len[x][y],1+len[xx][yy]);
            }
        }
    }

    static void test() {
        int n,m;
        Solution sol;
        while(cin>>n>>m) {
            vector<vector<int>> matrix(n,vector<int>(m,0));
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j)
                    cin>>matrix[i][j];
            cout<<"ans="<<sol.longestIncreasingPath(matrix)<<endl;
        }
    }
};
