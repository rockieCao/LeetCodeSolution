#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation
**/
class NestedInteger {
   public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     vector<NestedInteger> &getList() const;
 };

class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		beg.push(nestedList.begin());
		end.push(nestedList.end());
	}

	int next() {
		int res = beg.top()->getInteger();
		beg.top()++;
		return res;
	}

	bool hasNext() {
		while (!beg.empty()) {
			vector<NestedInteger>::iterator it = beg.top();
			if (it == end.top()) {
				beg.pop();
				end.pop();
			}
			else
			{
				if (it->isInteger()) {
					return true;
				}

				beg.top()++; //need to increase by 1 because next time we need to access next element
				beg.push(it->getList().begin()); //note: need to list before beg.top() increase by 1
				end.push(it->getList().end());
			}
		}
		return false;
	}

private:
	stack<vector<NestedInteger>::iterator> beg, end;
};

class NestedIterator2 {
public:
	NestedIterator2(vector<NestedInteger> &nestedList) {
		for (int i = nestedList.size() - 1; i >= 0; --i) {
			s.push(nestedList[i]);
		}
	}

	int next() {
		NestedInteger t = s.top(); s.pop();
		return t.getInteger();
	}

	bool hasNext() {
		while (!s.empty()) {
			NestedInteger t = s.top();
			if (t.isInteger()) return true;
			s.pop();
			for (int i = t.getList().size() - 1; i >= 0; --i) {
				s.push(t.getList()[i]);
			}
		}
		return false;
	}

private:
	stack<NestedInteger> s;
};
/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/
