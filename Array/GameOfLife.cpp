#include<iostream>
#include<string>
#include<vector>
using namespace std;

// use bit to store state and simulate

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        if(n==0) return;
        int m=board[0].size();
        if(m==0) return;
        
        for(int i=0;i<n;++i) {
        	for(int j=0;j<m;++j) {
				int lives=0;
				for(int x=i-1;x<=i+1;++x) {
					for(int y=j-1;y<=j+1;++y) {
						if(x<0||y<0||x>=n||y>=m||(x==i&&y==j)) continue;
						if((board[x][y]&0x01)==0x01) lives++;
					}
				}
				if(board[i][j]==0) {
					if(lives==3) board[i][j]|=0x02;	
				}
				else {
					if(lives==2||lives==3) board[i][j]|=0x02;	
				}
			}
        }
        for(int i=0;i<n;++i) {
        	for(int j=0;j<m;++j) {
				board[i][j]=((board[i][j]&0x02)>>1);
			}
        }
    }
};
