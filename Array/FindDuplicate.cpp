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
    
    //sol2: binary search+�볲ԭ�� O(nlogn)
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
	/*����������û���ظ��������ǿ���������ôһ�㣬���ǽ�������±��1��nÿһ����һ��һ��ӳ��������
	����������213,��ӳ���ϵΪ0->2, 1->1, 2->3���������һ��һӳ���ϵ��һ������f(n)������n���±꣬f(n)��ӳ�䵽������
	������Ǵ��±�Ϊ0����������������������һ��ֵ�������ֵΪ�µ��±꣬��������������㣬�Դ����ƣ�ֱ���±곬�硣
	ʵ���Ͽ��Բ���һ����������һ�������С�����������������������±�����У�0->2->3��

    ��������ظ��Ļ������м�ͻ�������һ��ӳ�䣬��������2131,��ӳ���ϵΪ0->2, {1��3}->1, 2->3��
	�������������ݵ����о�һ�����л�·�ˣ������±��������0->2->3->1->1->1->1->...���������������ظ�������
	����ת��Ϊ�󻷵��������⣨����֮���Բ��ÿ���ָ���һ�������ĵ���Ϊ����ֵ��ԭ���ǣ����ǹ����ʵ�����±������ֵ������ֵ�������:
	0[sub]->2[val]->2[sub]->3[val]->3[sub]->1[val]->1[sub]->1[val]->1[sub]->...����ô��һ�������ĵ㲻ȷ�����±껹������ֵ�����ǻ�����ʼ��һ��������ֵ��
	���Ի�Ҫ���ҵ�������㣩 
	
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
