#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
		if (k%n==0) return;
		int t = n-k%n;
		rotateArray(nums, t, n-1);
		rotateArray(nums, 0, t-1);
		rotateArray(nums, 0, n-1);

    }

	void rotateArray(vector<int>& arr, int s, int t)
	{
		for (int i = s, j = t; i < j; i++, j--)
		{
			swap(arr[i],arr[j]);
		}
	}
};