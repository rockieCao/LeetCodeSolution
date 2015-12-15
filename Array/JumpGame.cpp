#include <iostream>
#include <vector>
using namespace std;

// Problem:
// Given an array of non-negative integers, you are initially positioned at the first index of the array. 
// Each element in the array represents your maximum jump length at that position. 
// Determine if you are able to reach the last index. 
// For example:
// A = [2,3,1,1,4], return true. 
// A = [3,2,1,0,4], return false. 

// Solution: Greedy O(N)
// globalMax records the furthest position we can reach if [0..i] is reachable.
// lastMax records the furthest position we can reach by jumping with max steps from start.
// i.e. assume we can reach i, then range [i..i+nums[i]] is reachable, globalMax is the furthest position we can get so far. 
//      if j>i+nums[i], try do a jump at any position within [i..i+nums[i]] to reach furthest place (gready). then check lastMax>=i?, if yes, it is reachable; else it isn't reachable.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
		if (sz == 0) return false;

		int globalMax = 0, lastMax = 0;
		for (int i=0; i<sz; i++)
		{
			if (i > lastMax)
			{
				lastMax = globalMax;
				if (lastMax < i) // cann't reach the end
					break;
			}
			globalMax = max(globalMax, i+nums[i]);
		}

		return lastMax>=sz-1;
    }

	static void test()
	{
		int A[] = {2,3,1,1,4};
		int B[] = {3,2,1,0,4};

		vector<int> nums(A,A+5);
		Solution sol;
		cout<<sol.canJump(nums)<<endl;
		vector<int> num2(B,B+5);
		cout<<sol.canJump(num2)<<endl;
	}
};