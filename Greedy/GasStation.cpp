#include <iostream>
#include <vector>
using namespace std;

/*对于站点 i，我们把 gas[i] - cost[i] 当作整体考虑，我们用diff[i] = gas[i] - cost[i] 表示从当前站点出发，到下一个站点后剩余的油量。
因此结合司机的经验，题目就是需要找出这么一个点，从这个点出发，diff的累加值能达到峰值。
这道题就是求diff[]数组上的 和最大连续子序列，这个最大子序列的起始点就是车的出发点!
这道题转化成了 求循环数组的最大子序列问题.
解法：利用动态规划，求出diff[0] 到 diff[size-1]这个非循环数组上的最大子序列MAX和
最小子序列MIN。然后比较MAX和 Total - MIN，选出较大值(Total为 diff数组所有元素和)。
当然，我们要求的不是最大子序列的和，而是最大子序列的其实位置。
因此，如果MAX 较大，返回MAX所代表的最大子序列的起始元素；否
则，返回MIN所代表的最小子序列末尾的下一个元素。 
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if (n==0) return -1;
        
        int curMax = gas[0]-cost[0], bestMax = gas[0]-cost[0], curMin = gas[0]-cost[0], bestMin=gas[0]-cost[0];
        int total = 0, posMax = 0, cpMax = 0, posMin = 0;
        for (int i=0; i<n; i++) {
            int diff=gas[i]-cost[i];
            total += diff;
            if (curMax<0) {
                curMax=diff;
                cpMax=i;
            }
            else {
                curMax+=diff;   
            }
            if (curMax>bestMax) {
                bestMax = curMax;
                posMax = cpMax;   
            }
            if (curMin>0) {
                curMin=diff;
            }
            else {
                curMin+=diff;   
            }
            if (curMin<bestMin) {
                bestMin = curMin;
                posMin = (i+1)%n;   
            }
        }
        if (total < 0) return -1;
        else {
            if(bestMax>total-bestMin) return posMax;
            else return posMin;   
        }
    }
};
