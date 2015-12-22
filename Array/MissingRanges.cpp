#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*Problem: Missing Ranges
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.
For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

Solution:
*/
class Solution {
public:
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> ret;
        if(n==0) {
            ret.push_back(to_string(lower)+"->"+to_string(upper));
            return ret;
        }
        int pre=lower-1;
        for(int i=0;i<n;++i) {
            int cur=A[i];
            if(cur<lower) cur=lower-1;
            else if(cur>upper) cur=upper+1;
            if(cur-pre==2) {
                ret.push_back(to_string(pre+1));
            }
            else if(cur-pre>2) {
                ret.push_back(to_string(pre+1)+"->"+to_string(cur-1));
            }
            pre=cur;
        }
        if(upper-pre==1) ret.push_back(to_string(pre+1));
        else if(upper-pre>1) ret.push_back(to_string(pre+1)+"->"+to_string(upper));
        
        return ret;
    }
    
    static void test() {
        int n,x,lower,upper;
        Solution sol;
        while(cin>>n>>lower>>upper) {
            int *A = new int[n];
            for(int i=0;i<n;++i) {
                cin>>x;
                A[i]=x;
            }
            vector<string> ret=sol.findMissingRanges(A, n, lower, upper);
            cout<<"ans=[";
            for(int i=0;i<ret.size();++i)
                cout<<ret[i]<<",";
            cout<<"]"<<endl;
        }
    }
};
