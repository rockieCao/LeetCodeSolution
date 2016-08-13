#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> record;

	Solution(vector<int> nums) {
		for (int elem : nums) {
			record.push_back(elem);
		}
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return record;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> res(record.begin(), record.end());
		int n = record.size();
		for (int i = 0; i < n; ++i) {
			int j = i + rand() % (n - i);
			swap(res[i], res[j]);
		}
		return res;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/