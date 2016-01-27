#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

/*Problem: Meeting Rooms II
Given an array of meeting time intervals consisting of start and end times  [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
 Given [[0, 30],[5, 10],[15, 20]],
 return 2.

Solution: Greedy (O(nlogn))
sort intervals by start time in ascending order
always pick the earliest end time and extend it; if there's no such end time, add one rooms and insert current end time.
*/

class Solution {
public:
    struct Interval {
        int s,e;
        Interval(int _s, int _e): s(_s),e(_e) {}  
        
        friend bool operator<(const Interval& a, const Interval& b) {
            return a.s<b.s;   
        }
    };
    
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        if (n==0) return 0;
        if (n==1) return 1;
        sort(intervals.begin(), intervals.end());
        priority_queue<int,vector<int>,greater<int>> pq; //by default, it is high value first queue
        int rooms=1;
        pq.push(intervals[0].e);
        for(int i=1;i<n;++i) {
            int minEnd=pq.top();
            if(minEnd<=intervals[i].s) {
                pq.pop();
                pq.push(intervals[i].e);   
            }
            else {
                ++rooms;
                pq.push(intervals[i].e);   
            }
        }
        return rooms;
    }
    
    static void test() {
        int n,s,e;
        Solution sol;
        while(cin>>n) {
            vector<Interval> vec;
            for(int i=0;i<n;++i) {
                cin>>s>>e;
                vec.push_back(Interval(s,e));
            }
            cout<<"ans="<<sol.minMeetingRooms(vec)<<endl;
        }
    }
};

