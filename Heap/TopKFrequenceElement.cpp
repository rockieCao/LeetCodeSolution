#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) { // Í°ÅÅÐò O(n)
		vector<int> ret;
		unordered_map<int, int> hash;
		for (int x : nums)
			hash[x]++;
		vector<vector<int> > buckets(nums.size() + 1);
		for (auto it : hash)
			buckets[it.second].push_back(it.first);
		for (int i = buckets.size() - 1; i > 0; --i)
		{
			for (auto num : buckets[i]) {
				ret.push_back(num);
				if (ret.size() == k) return ret;
			}
		}
		return ret;
	}

	vector<int> topKFrequent2(vector<int>& nums, int k) { // Ð¡¸ù¶Ñ O(nlogk)
		vector<int> ret;
		unordered_map<int, int> hash;
		for (int x : nums)
			hash[x]++;
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> >> heap; // little root heap
		
		for (auto it : hash) {
			heap.push(make_pair(it.second, it.first));
			if (heap.size() > k) heap.pop();
		}

		while (!heap.empty()) {
			ret.push_back(heap.top().second);
			heap.pop();
		}

		return ret;
	}

	static void test() {
		int x, k, n;
		vector<int> nums;
		Solution sol;

		while (cin >> n >> k)
		{
			for (int i = 0; i < n; ++i) {
				cin >> x;
				nums.push_back(x);
			}
			vector<int> ret = sol.topKFrequent(nums, k);
			cout << "result = ";
			for (int i : ret) {
				cout<<i<<",";
			}
			cout<<endl;
		}
	}
};
