#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
		if (row == 0) return;
		int col = matrix[0].size();
		if (col == 0) return;

		bool firstrowzero = false, firstcolzero = false;
		for (int i = 0; i < col; i++)
			if (matrix[0][i] == 0)
			{
				firstrowzero = true;
				break;
			}
		for (int i = 0; i < row; i++)
			if (matrix[i][0] == 0)
			{
				firstcolzero = true;
				break;
			}
		for (int i = 1; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					break;
				}
			}
		for (int i = 1; i < col; i++)
			for (int j = 0; j < row; j++)
			{
				if (matrix[j][i] == 0)
				{
					matrix[0][i] = 0;
					break;
				}
			}

		for (int i = 1; i < row; i++)
			for (int j = 1; j < col; j++)
			{
				if (matrix[i][0] == 0||matrix[0][j]) matrix[i][j]=0;
			}
		if (firstrowzero)
			for (int i = 0; i < col; i++) matrix[0][i] = 0;
		if (firstcolzero)
			for (int i = 0; i < row; i++) matrix[i][0] = 0;
		
    }
};