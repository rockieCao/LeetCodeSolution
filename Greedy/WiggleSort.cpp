#include <iostream>
#include <vector>
using namespace std;

/*Wiggle Sort
Total Accepted:  1291 Total Submissions:  3008 Difficulty: Medium 

Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].

Solution: Greedy O(n)
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        for(int i=1; i<n; ++i) {
            if((i%2==1&&nums[i]<nums[i-1])||(i%2==0&&nums[i]>nums[i-1])) {
                swap(nums[i],nums[i-1]);   
            }
        }
    }
    
    static void test() {
        int n;
        Solution sol;
        while(cin>>n) {
            vector<int> nums(n,-1);
            for(int i=0; i<n; ++i) {
                cin>>nums[i];
            }
            sol.wiggleSort(nums);
            cout<<"ans="<<endl;
            for(int i=0; i<n; ++i) {
                cout<<nums[i]<<",";   
            }
            cout<<endl;
        }
    }
};

