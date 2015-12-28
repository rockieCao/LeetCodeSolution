#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Problem: 'A'->1,'Z'->26, given a string (e.g. "12"), return how many decode ways (e.g. 2 ways here. "AB" OR "L")
 * Test cases: "" return 0;
 *             "0" return 0;
 *             "127" return 2;
 */

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n==0) return 0;
        if (n==1) return s[0]>='1'?1:0;
        vector<int> dp(n,0);
        dp[0]=(s[0]>='1'?1:0);
        for (int i=1;i<n;i++) {
            if(s[i]>='1'&&dp[i-1]>0) dp[i]=dp[i-1];
            if((s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6'))&&(i==1||dp[i-2]>0)) dp[i]+=(i==1?1:dp[i-2]);
        }
        return dp[n-1];
    }
};
