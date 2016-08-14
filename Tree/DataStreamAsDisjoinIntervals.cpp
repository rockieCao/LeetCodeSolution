#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
	struct Interval {
		int start;
		int end;
		Interval() : start(0), end(0) {}
		Interval(int s, int e) : start(s), end(e) {}
	};

	struct Cmp {
		bool operator()(Interval a, Interval b) {
			return a.start < b.start;
		}
	};

	set<Interval, Cmp> st;

	/** Initialize your data structure here. */
	Solution() {

	}

	void addNum(int val) {
		auto it = st.lower_bound(Interval(val, val));
		int s = val, e = val;
		if (it != st.begin() && (--it)->end + 1 < val) ++it;
		while(it != st.end() && val + 1 >= it->start && val - 1 <= it->end) { //merge intervals
			s = min(s, it->start);
			e = max(e, it->end);
			it = st.erase(it);
		}
		st.insert(it, Interval(s, e));
	}

	// algo2
	vector<Interval> v;
	void addNum2(int val) { //分情况讨论：无重叠，相邻， 有重叠
		Interval cur(val, val);
		vector<Interval> res;
		int pos = 0;
		for (auto a : v) {
			if (cur.end + 1 < a.start)
				res.push_back(a);
			else if (cur.start > a.end + 1) {
				res.push_back(a);
				++pos;
			}
			else if (cur.start - 1 == a.end) {
				cur.start = a.start;
			}
			else if (cur.end + 1 == a.start) {
				cur.end = a.end;
			}
			else {
				cur.start = min(cur.start, a.start);
				cur.end = max(cur.end, a.end);
			}
		}
		res.insert(res.begin() + pos, cur);
		v = res;
	}

	vector<Interval> getIntervals() {
		vector<Interval> result;
		for (auto val : st)
			result.push_back(val);
		return result;
	}

	static void test() {
		Solution obj;
		int cmd, x;
		while (cin >> cmd) {
			if (cmd == 1) {
				cin >> x;
				obj.addNum(x);
			}
			else {
				vector<Interval> res = obj.getIntervals();
				for (auto it : res)
					cout << it.start << ":" << it.end << endl;
			}
		}
	}
};

/**
* Your SummaryRanges object will be instantiated and called as such:
* SummaryRanges obj = new SummaryRanges();
* obj.addNum(val);
* vector<Interval> param_2 = obj.getIntervals();
*/
