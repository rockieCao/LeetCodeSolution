#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
		if (sz == 0) return 0;

		vector<int> left(sz,-1), right(sz,-1);
		left[0] = 0;
		for (int i = 1; i < sz; i++) {
			left[i] = i;
			int j = left[i-1];
			while (j>=0&&height[i]<=height[j])
			{
				left[i] = j;
				if (j == left[j]) break;
				j = left[j];
			}
		}

		int ans = 0;
		right[sz-1] = sz-1;
		for (int i=sz-2; i>=0; i--) {			
			right[i] = i;
			int j = right[i+1];
			while (j<sz&&height[i]<=height[j])
			{
				right[i] = j;
				if (j == right[j]) break;
				j = right[j];
			}

			ans += min(height[left[i]],height[right[i]])-height[i];
		}

		return ans;
    }

	int trap2(vector<int>& height) {
		int sz = height.size();
		if (sz == 0) return 0;

		int left = 0, right = sz-1;
		while (left+1<sz)
		{
			if (height[left+1]>=height[left]) ++left;
			else break;
		}

		while (right-1>=0)
		{
			if (height[right-1]>=height[right]) --right;
			else break;
		}

		vector<int> lmax(sz);
		int mmax = height[left];
		for (int i = left+1; i < right; i++)
		{
			lmax[i] = mmax;
			if (height[i] > mmax)
				mmax = height[i];
		}
		mmax = height[right];
		int ans = 0;
		for (int i = right-1; i> left; i--)
		{
			int mmin = min(mmax, lmax[i]);
			if (mmin > height[i])
				ans += mmin-height[i];
			if (height[i] > mmax)
				mmax = height[i];
		}
		return ans;
	}

	static void test() {
		int n, x;
		vector<int> vec;
		cin>>n;
		for (int i = 0; i < n; i++) {
			cin>>x;
			vec.push_back(x);
		}
		Solution sol;
		cout<<sol.trap2(vec)<<endl;
	}
};
