#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

/*����poj�Ķ���˹����
���ƶ�λ��LIS���⣺����Ҫ�����е��ŷⰴ��С�����������ȸ��ݿ�ȴ�С�����ţ���������ͬ����ô�߶�С����ǰ�棬����STL����sort��Ĭ���ŷ���
�������ǲ���д������comparator��ֱ���žͿ����ˣ�Ȼ�����ǿ�ʼ����������ÿһ���ŷ⣬���Ƕ�������ǰ�����е��ŷ⣬
�����ǰ�ŷ�ĳ��Ϳ���ǰ���Ǹ��ŷ�Ĵ���ô���Ǹ���dp���飬ͨ��dp[i] = max(dp[i], dp[j] + 1)��

�Ż���ʹ�ö��ֲ��ҷ����Ż��ٶȣ���������Ҫ���Ļ��Ǹ��ŷ����򣬵�����������������Щ��ͬ���ŷ�Ŀ�Ȼ��Ǵ�С�����ţ����ǿ�����ʱ�������ø߶ȴ����ǰ�档����֤���Ž��в�����������ŷ�����ȵ������
��ô��������ͼ��˳����Ҹ߶������е�LIS����ȫ�ͺ�֮ǰ�ǵ�Longest Increasing Subsequenceһ����
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
			while (left < right) { // ������lower_bound����ʵ�֣�auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
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
