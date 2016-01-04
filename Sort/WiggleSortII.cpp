#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) { // sort based. O(nlogn)
        int n=nums.size();
        if(n<=1) return;
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        for(int i=0, j=(n+1)/2, k=n;i<n;++i) { // construct result in reverse order to handle cases like [4,5,5,6]. i.e. median value is duplicate
            if(i%2==0) nums[i]=temp[--j];
            else nums[i]=temp[--k];
        }
        
    }
    
    static void test() {
        Solution sol;
        int n;
        while(cin>>n) {
            vector<int> nums(n,-1);
            for(int i=0;i<n;++i)
                cin>>nums[i];
            sol.wiggleSort(nums);
            cout<<"ans=[";
            for(auto v:nums)
                cout<<v<<",";
            cout<<"]"<<endl;
        }
    }
};

