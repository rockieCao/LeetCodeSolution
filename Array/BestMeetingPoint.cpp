#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Problem
Best Meeting Point

Total Accepted:  701 Total Submissions:  1714 Difficulty: Medium

A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated usingManhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and(2,2):
1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.


Solution
二维的等于一维的相加, 一维的最小点必在median点(用反证法可以证明).
*/

class Solution {
public:
	int minTotalDistance(vector<vector<int>> grid) {  
		int n=grid.size();
		if(n==0) return 0;
		int m=grid[0].size();
		if(m==0) return 0;
		vector<int> xlist, ylist;
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				if(grid[i][j]==1) {
					xlist.push_back(i);
					ylist.push_back(j);
				}
			}
		}
		
		//sort(xlist.begin(),xlist.end());
		int res=0;
		n=xlist.size();
		for(int i=0;i<n;++i)
			res+=abs(xlist[i]-xlist[n/2]);
		sort(ylist.begin(),ylist.end());
		for(int i=0;i<n;++i)
			res+=abs(ylist[i]-ylist[n/2]);
		return res;
	}
	
	static void test() {
		Solution sol;
		int n,m;
		vector<vector<int>> g;
		while(cin>>n>>m) {
			int x;
			for(int i=0;i<n;++i) {
				vector<int> vec(m,0);
				for(int j=0;j<m;++j)
					cin>>vec[j];
				g.push_back(vec);
			}
			cout<<"ans="<<sol.minTotalDistance(g)<<endl;
		}
	}
};
