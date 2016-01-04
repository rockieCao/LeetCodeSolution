#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * divide into 3 stages:
 * 1) process all intervals before newInterval.start
 * 2) merge intersection part //<--- need to handle carefully
 * 3) append other intervals after newInterval.end
 */
class Solution {
public:
    struct Interval {
        int start;
        int end;
        Interval(): start(0), end(0) {}
        Interval(int s, int e): start(s), end(e) {}
    };

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) { //intervals already sorted. O(N)
        int sz = intervals.size();
        vector<Interval> ret;
        if (sz == 0) { ret.push_back(newInterval); return ret; }
        
        int i = 0;
        while (i < sz && newInterval.start > intervals[i].end)
        {
            ret.push_back(intervals[i]);
            ++i;
        }

        if (i < sz)
            newInterval.start = min(newInterval.start, intervals[i].start);
        while (i < sz && newInterval.end >= intervals[i].start)
        {
            newInterval.end = max(newInterval.end, intervals[i].end);
            ++i;
        }
        ret.push_back(newInterval);
        while (i < sz)
        {
            ret.push_back(intervals[i]);
            ++i;
        }

        return ret;
    }

    static void test() {
        int n, x, y;
        cin>>n;
        vector<Interval> vec;
        for (int i = 0; i < n; i++)
        {
            cin>>x>>y;
            vec.push_back(Interval(x,y));
        }
        
        cin>>x>>y;
        Interval newInterval(x,y);

        Solution sol;
        cout<<"ans = "<<endl;
        vector<Interval> ans = sol.insert(vec, newInterval);
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i].start<<","<<ans[i].end<<endl;
        }
    }
};