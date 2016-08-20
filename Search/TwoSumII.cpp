#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> res;
		int s = 0, e = numbers.size() - 1;
		while (s < e) {
			int sum = numbers[s] + numbers[e];
			if (sum == target)
				break;
			else if (sum > target)
				--e;
			else
				++s;
		}
		res.push_back(s+1);
		res.push_back(e+1);
		return res;
	}
};
