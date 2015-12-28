#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//O(N) DP solution:
/*buy[i]表示在第i天之前最后一个操作是买，此时的最大收益。
sell[i]表示在第i天之前最后一个操作是卖，此时的最大收益。

buy[i]=max{sell[i-2]-p[i],buy[i-1]}; //cold down 1 day
sell[i]=max{buy[i-1]+p[i],sell[i-1]};

可以用滚动数组优化内存 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        
        int buy=INT_MIN, preBuy=0, sell=0, preSell=0;
        for(int p:prices) {
            preBuy=buy;
            buy=max(preSell-p,preBuy);
            preSell=sell;
            sell=max(preBuy+p,preSell);    
        }
        return sell;
    }
    
    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;
        
        vector<int> dp(n), mmin(n);
        dp[0]=0;
        dp[1]=max(0,prices[1]-prices[0]);
        int ans=max(dp[0],dp[1]);
        
        for(int i=2;i<n;++i) {
            dp[i]=max(dp[i-2],dp[i-1]);
            mmin[i]=prices[i];
            for(int j=i-1;j>=0;--j) {
                if(dp[i]<prices[i]-prices[j]) dp[i]=prices[i]-prices[j];
                if(prices[j]<mmin[j+1]) mmin[j]=prices[j];
                else mmin[j]=mmin[j+1];
            }
            for(int j=1;j<=i-3;++j) {
                if(dp[i]<dp[j]+prices[i]-mmin[j+2])
                    dp[i]=dp[j]+prices[i]-mmin[j+2];
            }
            if(ans<dp[i]) ans=dp[i];
        }
        return ans;
    }
};
