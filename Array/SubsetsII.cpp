#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// generate all subsets for array which may contains duplicate elements

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int sz = nums.size();
		vector<vector<int>> ret;
		if (sz == 0) return ret;

		map<int,int> mp;
		vector<int> nu;
		for (int elem : nums)
		{
			if (mp.find(elem)==mp.end())
			{
				mp[elem] = 1;
				nu.push_back(elem);
			}
			else
				mp[elem]++;
		}
		sz = nu.size();
		sort(nu.begin(), nu.end());

		search(0, sz, nu, mp, vector<int>(), ret);

		return ret;
    }

	void search(int start, int end, vector<int>& nu, map<int,int>& mp, vector<int> path, vector<vector<int>>& ret) {
		if (start == end)
		{
			ret.push_back(path);
			return;
		}

		search(start+1, end, nu, mp, path, ret);
		for (int i = mp[nu[start]]; i > 0; --i)
		{
			path.push_back(nu[start]);
			search(start+1, end, nu, mp, path, ret);
		}
		for (int i = mp[nu[start]]; i > 0; --i)
		{
			path.pop_back();
		}
	}

	static void test() {
		int n, x;
		vector<int> vec;
		cin>>n;
		for (int i = 0; i < n; i++)
		{
			cin>>x;
			vec.push_back(x);
		}

		Solution sol;
		vector<vector<int>> ret = sol.subsetsWithDup(vec);
		for (int i=0; i < ret.size(); i++)
		{
			for (int elem: ret[i])
			{
				cout<<" "<<elem;
			}
			cout<<endl;
		}
	}
};