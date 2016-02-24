#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*Problem: StrobogrammaticNumberIII
Description: similar to StrobogrammaticNumberII, Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high
Note: low, high can be very large number.
*/

class Solution {
public:
    unordered_map<char, char> d;
    vector<char> single;
    string low, high;
    
    Solution(){
        d.insert(pair<char, char>('0','0'));
        d.insert(pair<char, char>('1','1'));
        d.insert(pair<char, char>('6','9'));
        d.insert(pair<char, char>('8','8'));
        d.insert(pair<char, char>('9','6'));
        
        single.push_back('0');
        single.push_back('1');
        single.push_back('8');
        single.push_back('6');
        single.push_back('9');
    }
    
    int findStrobogrammatic(string _low, string _high) {
        int ans=0;
        low=_low;
        high=_high;
        
        for(int i=low.length(); i<=high.length(); i++) {
            string tmp(i,' ');
            search(0, i-1, tmp, ans);
        }
        
        return ans;
    }
    
    void search(int s, int e, string cur, int& ans) {
        if(s>e) {
            if((cur[0]!='0'||cur.length()==1)&&less(low,cur)&&less(cur,high))
                ans++;
            return;  
        }
        for(auto elem:d) {
            cur[s]=elem.first;
            cur[e]=elem.second;
            if((s==e&&elem.first==elem.second)||s<e)
                search(s+1,e-1,cur,ans);    
        }
    }
    
    bool less(string& s, string& t) {
        int ls=s.length(),lt=t.length();
        if(ls!=lt) return ls<lt;
        int i;
        for(i=0;i<ls;++i)
            if(s[i]!=t[i]) break;
        return i==ls||s[i]<t[i];
    }
    
    static void test() {
        Solution sol;
        string lo, hi;
        while(cin>>lo>>hi) {
            cout<<"ans="<<sol.findStrobogrammatic(lo,hi)<<endl;
        }   
    }
};
