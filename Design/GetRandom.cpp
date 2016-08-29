#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:

	/** Initialize your data structure here. */
	RandomizedSet() {
		st = unordered_map<int,int>();
		vec = vector<int>();
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (st.find(val) != st.end()) return false;
		st[val] = vec.size();
		vec.push_back(val);
		
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (st.find(val) == st.end()) return false;
		vec[st[val]] = vec.back();
		st[vec.back()] = st[val];
		vec.pop_back();
		st.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int r = rand()%vec.size();
		return vec[r];
	}

	static void test() {
		RandomizedSet obj;
		string cmd;
		int x;
		while (cin >> cmd) {
			switch(cmd[0]) {
			case 'i':
				cin >> x;
				cout<<obj.insert(x)<<endl;
				break;
			case 'r':
				cin >> x;
				cout << obj.remove(x) << endl;
				break;
			case 'g':
				cout << obj.getRandom() << endl;
				break;
			}

		}
	}

private:
	unordered_map<int,int> st;
	vector<int> vec;
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/