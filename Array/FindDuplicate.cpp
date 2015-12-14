#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

/*Problem:find a duplicate number
Description:
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

https://leetcode.com/problems/find-the-duplicate-number/
*/
class Solution {
public:
	// sol1: reuse the signature position of original array element O(n)
    int findDuplicate2(vector<int>& nums) {
        int n=nums.size();
        if(n==2) return nums[0];
        int ans=-1;
        for(int i=0;i<n;++i) {
        	int x=abs(nums[i]); //need to make sure the subscribe is positive
        	if(nums[x-1]<0) {
        		ans=i;
				break;
        	}
        	nums[x-1]=-nums[x-1];
        }
        for(int i=0;i<ans;++i) {
        	int x=abs(nums[i]);
			nums[x-1]=-nums[x-1];
		}
        return nums[ans];
    }
    
    //sol2: binary search+鸽巢原理 O(nlogn)
	int findDuplicate3(vector<int>& nums) {
		int n=nums.size();
		if(n==2) return nums[0];
		int low=1,high=n,mid;
		while(low<=high) {
			mid=low+(high-low)/2;
			int cnt=0;
			for(int i=0;i<n;++i) {
				if(nums[i]<=mid) cnt++;
			}
			
			if(cnt>mid) high=mid-1;
			else low=mid+1;
		}
		return low;
	}
	
	//sol3: find break point in the circle O(n)
	/*假设数组中没有重复，那我们可以做到这么一点，就是将数组的下标和1到n每一个数一对一的映射起来。
	比如数组是213,则映射关系为0->2, 1->1, 2->3。假设这个一对一映射关系是一个函数f(n)，其中n是下标，f(n)是映射到的数。
	如果我们从下标为0出发，根据这个函数计算出一个值，以这个值为新的下标，再用这个函数计算，以此类推，直到下标超界。
	实际上可以产生一个类似链表一样的序列。比如在这个例子中有两个下标的序列，0->2->3。

    但如果有重复的话，这中间就会产生多对一的映射，比如数组2131,则映射关系为0->2, {1，3}->1, 2->3。
	这样，我们推演的序列就一定会有环路了，这里下标的序列是0->2->3->1->1->1->1->...，而环的起点就是重复的数。
	问题转化为求环的起点的问题（这里之所以不用快慢指针第一次相遇的点作为返回值，原因是：我们构造的实际是下标和数组值交替出现的链表，即:
	0[sub]->2[val]->2[sub]->3[val]->3[sub]->1[val]->1[sub]->1[val]->1[sub]->...，那么第一次相遇的点不确定是下标还是数组值，但是环的起始点一定是数组值，
	所以还要再找到环的起点） 
	
	*/
	int findDuplicate(vector<int>& nums) {
		int n=nums.size();
		if(n==2) return nums[0];
		int slow=0,fast=0;
		
		//find circle
		do {
			slow=nums[slow];
			fast=nums[nums[fast]];
		}while(slow!=fast);
		
		//find first meet point
		fast=0;
		while(fast!=slow) {
			slow=nums[slow];
			fast=nums[fast];
		}
		
		return fast;
	}
};
