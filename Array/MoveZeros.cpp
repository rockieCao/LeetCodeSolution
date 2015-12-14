#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return;
        int i=0,j=0;
        while(i<n) {
        	if(nums[i]!=0) {
        		nums[j]=nums[i];
        		++j;
				++i;
			}
			else {
				++i;
			}
        }
        while(j<n) nums[j++]=0;
        
    }
};
