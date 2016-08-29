#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ctime>
using namespace std;

class RandomizedCollection {
	/*
	The key of m is the val, the value of m is a vector contains indices where the val appears in nums.
	Each element of nums is a pair, the first element of the pair is val itself, the second element of the pair is an index into m[val]. [This is optimization]
	There is a relationship between nums and m:

	m[nums[i].first][nums[i].second] == i;
	*/

public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		auto result = m.find(val) == m.end();

		m[val].push_back(nums.size());
		nums.push_back(pair<int, int>(val, m[val].size() - 1));

		return result;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		auto result = m.find(val) != m.end();
		if (result)
		{
			auto last = nums.back();
			m[last.first][last.second] = m[val].back();
			nums[m[val].back()] = last;
			m[val].pop_back();
			if (m[val].empty()) m.erase(val);
			nums.pop_back();
		}
		return result;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return nums[rand() % nums.size()].first;
	}
private:
	vector<pair<int, int>> nums;
	unordered_map<int, vector<int>> m;
};


class RandomizedCollection2 {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {
		srand(time(NULL));
	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		if (mp.find(val) == mp.end())
			mp[val] = vector<int>();
		mp[val].push_back(vec.size());
		vec.push_back(val);
		return mp[val].size() == 1;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if (mp.count(val)==0) return false;
		int lastNum = vec.back(), idx = mp[val].back();
		mp[val].pop_back();
		if (mp[val].size() == 0) mp.erase(val);
		int sz = vec.size();
		if (idx != sz - 1)
		{
			vec[idx] = lastNum;
			//mp[lastNum].back() = idx; //this won't work because the back element is not guaranteed to be the last index of vec
			for (int i = 0; i < mp[lastNum].size(); ++i) { //Note: need to find the element which is last index of vec and replace its value
				if (mp[lastNum][i] == (sz - 1)) {
					mp[lastNum][i] = idx;
					break;
				}
			}
		}
		vec.pop_back();
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() {

		return vec[rand()%vec.size()];
	}

private:
	unordered_map<int, vector<int> > mp;
	vector<int> vec;
};

/**
* Your RandomizedCollection object will be instantiated and called as such:
* RandomizedCollection obj = new RandomizedCollection();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/