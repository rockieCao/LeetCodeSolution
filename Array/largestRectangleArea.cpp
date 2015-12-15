#include <iostream>
#include <vector>
using namespace std;

// DP
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
		int n = height.size();
		if (n < 1) return 0;
		vector<int> maxleft(n), maxright(n,-1);
		for (int i = 0; i < n; i++)
		{
			maxleft[i] = i;
			int j = i-1;
			while (j>=0&&height[j]>=height[i])
			{
				maxleft[i] = maxleft[j];
				j = maxleft[j]-1;
			}
		}
		int area = height[0];
		for (int i = n-1; i>=0; i--)
		{
			maxright[i] = i;
			int j = i+1;
			while (j<n&&height[j]>=height[i])
			{
				maxright[i] = maxright[j];
				j = maxright[j]+1;
			}

			int tmp = height[i]*(maxright[i]-maxleft[i]+1);
			if (tmp > area)
				area = tmp;
		}

		return area;
    }

	static void test() {
		int n,x;
		vector<int> height;
		cin>>n;
		for(int i = 0; i < n; i++)
		{
			cin>>x;
			height.push_back(x);
		}
		Solution sol;
		cout<<"result="<<sol.largestRectangleArea(height)<<endl;
	}
};