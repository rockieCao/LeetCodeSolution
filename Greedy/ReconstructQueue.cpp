#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct cmp {
	bool operator() (const pair<int, int> a, const pair<int, int> b)
	{
		if (a.second != b.second) return a.second < b.second;
		else return a.first < b.first;
	}
};

struct Node {
	int val;
	Node *next;
	Node(int _val) :val(_val), next(NULL) {}
};

class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		int n = people.size();
		if (n == 0) return vector<pair<int, int> >(); //Note: boundary condition

		vector<pair<int, int> > res;
		Node *llist = new Node(-1);

		sort(people.begin(), people.end(), cmp());

		llist->next = new Node(0);
		for (int i = 1; i < n; ++i) {
			Node *cur = llist->next, *pre = NULL;
			int height = people[i].first, cnt = people[i].second;
			while (cur!=NULL) {
				if (people[cur->val].first >= height)
				{
					--cnt;
					if (cnt < 0) { // 贪心：每次当前队列的头部向后扫描，当遇到第cnt+1个比cur大的元素时停止，插入到当前位置
						Node *np = new Node(i);
						np->next = cur;
						pre->next = np;
						break;
					}
				}
				pre = cur;
				cur = cur->next;
			}
			if (cnt >= 0) {
				pre->next = new Node(i);
			}
		}

		Node *cur = llist->next;
		while (cur != NULL) {
			res.push_back(people[cur->val]);
			cur = cur->next;
		}

		return res;
	}

	vector<pair<int, int>> reconstructQueue2(vector<pair<int, int>>& people) { //NB version
		vector<pair<int, int> > result;

		sort(people.begin(), people.end(), [](pair<int, int> a, pair<int, int> b) {
			return a.first > b.first || (a.first == b.first && a.second < b.second);
		});

		for (auto p : people) {
			result.insert(result.begin() + p.second, p);
		}

		return result;
	}
	
	static void test() {
		int n, height, cnt;
		vector<pair<int, int> > people;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> height >> cnt;
			people.push_back(make_pair(height, cnt));
		}
		vector<pair<int,int> > res = Solution().reconstructQueue(people);
		cout << "ans=";
		for (int i = 0; i < n; ++i) {
			cout << "[" << res[i].first << "," << res[i].second << "] ";
		}
		cout << endl;
	}
};
