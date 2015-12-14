#include<iostream>
#include<vector>
using namespace std;

class NumMatrix {
public:
	int n,m;
	vector<vector<int>> sum;
	
    NumMatrix(vector<vector<int>> &matrix) {
        n=matrix.size();
        if(n>0) {
	        m=matrix[0].size();
	        if(m>0) {
		        sum=vector<vector<int>>(n,vector<int>(m,0));
		        sum[0][0]=matrix[0][0];
		        for(int i=1;i<n;++i) sum[i][0]=sum[i-1][0]+matrix[i][0];
		        for(int j=1;j<m;++j) sum[0][j]=sum[0][j-1]+matrix[0][j];
		        for(int i=1;i<n;++i)
		        	for(int j=1;j<m;++j) {
		        		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i][j];	
		        	}
	        }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
    	if(n==0||m==0) return 0;
        valid(row1,0,n-1);
        valid(col1,0,m-1);
        valid(row2,0,n-1);
        valid(col2,0,m-1);
        int ans=sum[row2][col2];
        if(row1>=1) ans-=sum[row1-1][col2];
        if(col1>=1) ans-=sum[row2][col1-1];
        if(row1>=1&&col1>=1) ans+=sum[row1-1][col1-1];
        return ans;
    }
    
    void valid(int& val, int low, int high) {
        if(val<low) val=low;
        if(val>high) val=high;
    }	
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
