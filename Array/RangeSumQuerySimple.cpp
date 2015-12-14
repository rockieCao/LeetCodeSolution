#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
	int n;
	vector<int> sum;
	
    NumArray(vector<int> &nums) {
        int n=nums.size();
        sum=vector<int>(n,0);
        if(n>0) sum[0]=nums[0];
        for(int i=1;i<n;++i) sum[i]=sum[i-1]+nums[i];
    }

    int sumRange(int i, int j) {
        if(i>j) swap(i,j);
        if(j>=n) j=n-1;
        if(i<0) i=0;
        if(i==0) return sum[j];
        else return sum[j]-sum[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
