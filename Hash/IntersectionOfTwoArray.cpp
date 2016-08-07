#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ret;
		unordered_map<int,int> hash1, hash2;

		for (int x : nums1)
			hash1[x]++;
		for (int x : nums2)
			hash2[x]++;

		for (auto it : hash1)
		{
			if (hash2.count(it.first) > 0)
			{
				int cnt = min(it.second, hash2[it.first]);
				for (int i = 0; i < cnt; ++i)
					ret.push_back(it.first);
			}
		}
		return ret;
	}

	static void test() {
		int n1, n2, x;
		Solution sol;

		while (cin >> n1 >> n2) {
			vector<int> vec1, vec2;
			for (int i = 0; i < n1; ++i) {
				cin >> x;
				vec1.push_back(x);
			}
			for (int i = 0; i < n2; ++i) {
				cin >> x;
				vec2.push_back(x);
			}
			vector<int> ret = sol.intersect(vec1, vec2);
			cout << "result:";
			for (int x : ret)
				cout << x << ",";
			cout << endl;
		}
		
	}
};
