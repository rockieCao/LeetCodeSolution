#include<iostream>
#include<string>
#include<vector>
using namespace std;

class NumArray {
public:
	int n;
	vector<int> A,C;
	
    NumArray(vector<int> &nums) {
        n=nums.size();
        C=vector<int>(n+1,0);
        for(int i=0;i<n;++i) { //note: don't forget to do initialize
        	add(i, nums[i]);	
        }
        A=nums;
    }

    void update(int i, int val) {
    	add(i, val-A[i]);
    	A[i]=val; //note: need to update original array because we'll need to calculate the update delta based on previous value
    }

    int sumRange(int i, int j) {
    	++i;
    	++j;
        return sum(j)-sum(i-1);
    }
    
    int lowbit(int x) {
    	return x&-x;
	}
	
	int sum(int x) {
		int ret=0;
		while(x>0) {
			ret+=C[x];
			x-=lowbit(x);
		}
		return ret;
	}
	
	void add(int i,int delta) {//note: the 2nd parameter is delta value
		++i; //0->1
        while(i<=n) {
			C[i]+=delta;
			i+=lowbit(i);        		
        }	
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
