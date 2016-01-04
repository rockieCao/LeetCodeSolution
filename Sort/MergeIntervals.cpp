#include <iostream>
#include <vector>
#include <algorithm>
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
        Interval(): start(0), end(0) {}
        Interval(int s, int e): start(s), end(e) {}
    };

    /*struct comp {
        bool operator() (const Interval& a, const Interval& b)
        {
            if (a.start != b.start) return a.start < b.start;
            else return a.end > b.end;
        }
    };*/

    static bool cmp (const Interval& a, const Interval& b)
    {
        if (a.start != b.start)
            return a.start < b.start;
        else
            return a.end > b.end;
    }

    vector<Interval> merge(vector<Interval>& intervals) { //O(NlogN)
        int sz = intervals.size();
        if (sz <= 1) return intervals;

        sort(intervals.begin(), intervals.end(), cmp);

        vector<Interval> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < sz; i++)
        {
            Interval last = ans.back();
            if (intervals[i].start <= last.end && intervals[i].end > last.end)
            {
                last.end = intervals[i].end;
                ans.pop_back();
                ans.push_back(last);
            }
            else if(intervals[i].start > last.end)
            {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
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
        Solution sol;
        cout<<"ans = "<<endl;
        vector<Interval> ans = sol.merge(vec);
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i].start<<","<<ans[i].end<<endl;
        }
    }
};