#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(n==0) return amount>0?-1:0;
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        for(int c=1;c<=amount;++c) {
            for(int i=0;i<n;++i) {
                if(c-coins[i]>=0&&dp[c-coins[i]]>=0) {
                    if(dp[c]==-1||dp[c]>dp[c-coins[i]]+1)
                        dp[c]=dp[c-coins[i]]+1;
                }
            }
        }
        
        return dp[amount];
    }
    
    static void test() {
        int n,amount;
        Solution sol;
        while(cin>>n>>amount) {
            vector<int> coins(n,0);
            for(int i=0;i<n;++i) cin>>coins[i];
            cout<<"ans="<<sol.coinChange(coins,amount)<<endl;
        }
    }
};

