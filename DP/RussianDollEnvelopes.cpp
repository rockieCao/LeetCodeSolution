#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

/*类似poj的俄罗斯套娃
类似二位的LIS问题：首先要给所有的信封按从小到大排序，首先根据宽度从小到大排，如果宽度相同，那么高度小的再前面，这是STL里面sort的默认排法，
所以我们不用写其他的comparator，直接排就可以了，然后我们开始遍历，对于每一个信封，我们都遍历其前面所有的信封，
如果当前信封的长和宽都比前面那个信封的大，那么我们更新dp数组，通过dp[i] = max(dp[i], dp[j] + 1)。

优化：使用二分查找法来优化速度，我们首先要做的还是给信封排序，但是这次排序和上面有些不同，信封的宽度还是从小到大排，但是宽度相等时，我们让高度大的在前面。（保证最优解中不会存在两个信封宽度相等的情况）
那么现在问题就简化了成了找高度数字中的LIS，完全就和之前那道Longest Increasing Subsequence一样了
*/

bool cmp(pair<int, int> a, pair<int, int>& b) {
	if (a.first != b.first) return a.first < b.first;
	else return a.second > b.second;
}

bool cmp2(pair<int, int> a, pair<int, int>& b) {
	if (a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}

class Solution {
public:
	int maxEnvelopes(vector<pair<int, int> >& envelopes) {
		int n = envelopes.size();
		if (n <= 1) return n;
		sort(envelopes.begin(), envelopes.end(), cmp);
		vector<int> dp;
		
		for (int i = 0; i < n; ++i) {
			int left = 0, right = dp.size(), cur = envelopes[i].second;
			while (left < right) { // 可以用lower_bound函数实现：auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
				int mid = left + (right - left) / 2;
				if (dp[mid] < cur) left = mid + 1;
				else right = mid;
			}
			if (right >= dp.size()) dp.push_back(cur);
			else dp[right] = cur;
		}

		return dp.size();
	}

	int maxEnvelopes2(vector<pair<int, int> >& envelopes) {
		int n = envelopes.size();
		if (n <= 1) return n;
		sort(envelopes.begin(), envelopes.end(), cmp2);
		vector<int> dp(n + 1, 1);
		int ans = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}

		return ans;
	}
};
