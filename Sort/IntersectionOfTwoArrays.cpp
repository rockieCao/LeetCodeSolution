#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <hash_set>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		hash_set<int> hset(nums1.begin(), nums1.end()), res;
		for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it) {
			if (hset.count(*it) > 0)
				res.insert(*it);
		}

		return vector<int>(res.begin(), res.end());
	}
};
