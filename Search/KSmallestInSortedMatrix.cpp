#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size(), m = matrix[0].size();
		int left = matrix[0][0], right = matrix[n - 1][m - 1], mid;

		while (left < right) {
			mid = left + (right - left) / 2;
			int cnt = 0;
			for (int i = 0; i < n; ++i) {
				cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
			}
			if (cnt < k) left = mid + 1;
			else right = mid;
		}

		return left; //attention: this need to be the index in matrix
	}

	int kthSmallest2(vector<vector<int>>& matrix, int k) {
		int n = matrix.size(), m = matrix[0].size();
		priority_queue<int, vector<int>, less<int> > pq;
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				pq.push(matrix[i][j]);
				if (pq.size()>k) pq.pop();
			}
		}
		return pq.top();
	}
};
