#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    struct Interval{
        int s,e;
        Interval(int _s,int _e):s(_s),e(_e){} 
        
        friend bool operator<(const Interval& a, const Interval& b) {
            if(a.s==b.s) return a.e<b.e;
            else return a.s<b.s;   
        }
    };
    
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n<2) return true;
        sort(intervals.begin(), intervals.end());
        
        for(int i=1;i<n;++i) {
            if(intervals[i].s<intervals[i-1].e) return false;
        }
        return true;
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
            cout<<"ans="<<sol.canAttendMeetings(vec)<<endl;
        }
    }
};
