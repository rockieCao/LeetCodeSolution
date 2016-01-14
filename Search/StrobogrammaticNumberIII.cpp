#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include <sys/timeb.h>
#include<ctime>
#include<climits>
using namespace std;

/*Problem: Strobogrammatic Number III
The idea is similar to Strobogrammatic Number II: generate all those in-range strobogrammatic numbers and count.

Solution: enumerate according to length and judge whether current number liese [low,right]
Optimization: record the intermediate result, i.e. when enumber number with length i, try to see candidates with length i-1 (if i is odd) and i-2(if i is even)
              from runtime, it didn't show improvement!
Special case:
1.low and right can be very large and need to use string.
*/

class Solution{
private:
    unordered_map<char,char> mp;
    
    
public:
    Solution() {
        mp={{'0','0'},
        {'1','1'},
        {'6','9'},
        {'8','8'},
        {'9','6'}};
    }
    
    int strobogrammaticInRange(string low, string high) {
        int ans=0, left=low.length(), right=high.length();
        for(int l=left;l<=right;++l) {
            int pre=ans;
            string tmp(l,' ');
            search(0,l-1,tmp,ans,low,high);
            //cout<<"debug1:"<<l<<","<<ans-pre<<endl;
        }
        
        return ans;
    }
    
    void search(int left,int right,string tmp, int &ans, string &low, string &high) {
        if(left>right) {
            if((tmp[0]!='0'||tmp.length()==1)&&comp(tmp,low)>=0&&comp(tmp,high)<=0) {
                ++ans;   
            }
            return;
        }
        for(auto a:mp) {
            tmp[left]=a.first;
            tmp[right]=a.second;
            if(left<right||(left==right&&a.first==a.second)) search(left+1,right-1,tmp,ans,low,high);
        }
    }
    
    int comp(const string &a, const string &b) {
        int la=a.length(), lb=b.length();
        if(la!=lb) return la<lb?-1:1;
        else {
            for(int i=0;i<la;++i) {
                if(a[i]!=b[i]) return a[i]<b[i]?-1:1;   
            }
            return 0;
        }
    }
    
    int strobogrammaticInRange2(string low, string high) {
        unordered_map<int,vector<string>> records;
        
        int ans=0, left=low.length(), right=high.length();
        for(int l=left;l<=right;++l) {
            int pre=ans;
            records[l]=vector<string>();
            if(l%2==0) {
                if(records.find(l-2)!=records.end()) {
                    for(auto r:records[l-2]) {
                        string tmp(r.substr(0,(l-2)/2)+string("  ")+r.substr((l-2)/2));
                        //cout<<"***"<<"first r:"<<r.substr(0,(l-2)/2)<<endl;
                        //cout<<"***"<<"second r:"<<r.substr((l-2)/2)<<endl;
                        search2(l/2-1,l/2,tmp,ans,low,high,records);
                    }
                }
                else {
                    string tmp(l,' ');
                    search2(0,l-1,tmp,ans,low,high,records);
                }
            }
            else {
                if(records.find(l-1)!=records.end()) {
                    for(auto r:records[l-1]) {
                        string tmp = r.substr(0,(l-1)/2)+" "+r.substr((l-1)/2);
                        search2(l/2,l/2,tmp,ans,low,high,records);
                    }
                }
                else {
                    string tmp(l,' ');
                    search2(0,l-1,tmp,ans,low,high,records);
                }
            }
            //cout<<"debug2:"<<l<<","<<ans-pre<<endl;
        }
        
        return ans;
    }
    
    void search2(int left,int right,string tmp, int &ans, string &low, string &high, unordered_map<int,vector<string>>& records) {
        if(left>right) {
            if((tmp[0]!='0'||tmp.length()==1)) {
                records[tmp.length()].push_back(string(tmp));
                if(comp(tmp,low)>=0&&comp(tmp,high)<=0) {
                    ++ans;
                }
            }
            return;
        }
        for(auto a:mp) {
            tmp[left]=a.first;
            tmp[right]=a.second;
            if(left<right||(left==right&&a.first==a.second)) search2(left+1,right-1,tmp,ans,low,high,records);
        }
    }
    
    static void test() {
        string low,high;
        Solution sol;
        while(cin>>low>>high) {
            struct timeb startTime, startTime2, endTime, endTime2;
            ftime(&startTime);
            cout<<"ans="<<sol.strobogrammaticInRange(low,high)<<endl;
            ftime(&endTime);
            ftime(&startTime2);
            cout<<"ans2="<<sol.strobogrammaticInRange2(low,high)<<endl;
            ftime(&endTime2);
            cout<<"runTime1="<<(endTime.time-startTime.time)*1000+(endTime.millitm-startTime.millitm)<<"ms"<<endl;
            cout<<"runTime2="<<(endTime2.time-startTime2.time)*1000+(endTime2.millitm-startTime2.millitm)<<"ms"<<endl;
            
            
        }
    }
};

