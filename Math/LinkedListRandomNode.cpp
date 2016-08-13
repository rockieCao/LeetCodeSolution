#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

//Reservoir Sampling
class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	ListNode* start;

	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		start = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		int res = start->val;
		ListNode *tp = start->next;
		for (int i = 2; tp != NULL; ++i) {
			int r = rand() % i + 1; //1~i
			if (r <= 1)
				res = tp->val;
			tp = tp->next;
		}
		return res;
	}

	static void test() {
		int n, x;
		cin >> n;
		
		ListNode *head = NULL, *tail = NULL;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			ListNode* tp = new ListNode(x);
			if (head == NULL) {
				head = tp;
				tail = tp;
			}
			else {
				tail->next = tp;
				tail = tp;
			}
		}
		Solution sol(head);
		for (int i = 0; i < 10; ++i) {
			cout << "out: " << sol.getRandom() << endl;
		}
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/