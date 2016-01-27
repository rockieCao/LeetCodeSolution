#include<iostream>
#include<vector>
using namespace std;

/*Problem: Patching Array
Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n]
 inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

Solution: Greedy O(n)
Enumerate the value known (s here), if nums[i]<=s, then [1,s+nums[i]-1] will be available
else if nums[i]>s, then must add s, after that, [1,s-1+s] will be availabel

Note: since the addition or multiplication is betfor boundary check, value of s may be bigger than MAX_INT, so need to use long type.
*/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int m = nums.size(), ans=0;
        for(long s=1, i=0;s<=n;) {
            if(i<m&&nums[i]<=s) {
                s+=nums[i]; //[1,s+nums[i]-1] will be availabel
                ++i;
            }
            else {
                s<<=1; //add s then [1,2*s-1] will be availabel
                ans++;
            }
        }
        return ans;
    }
    
    static void test() {
        int m,n;
        Solution sol;
        while(cin>>m>>n) {
            vector<int> nums(m,0);
            for(int i=0;i<m;++i)
                cin>>nums[i];
            cout<<"ans="<<sol.minPatches(nums, n)<<endl;
        }
    }
};
