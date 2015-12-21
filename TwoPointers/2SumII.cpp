#include <iostream>
#include <vector>
using namespace std;

/*Problem: Two Sum II - input array is sorted
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

Solution: Two-pointer
*/

class Solution {
public:
    vector<int> twoSum(vector<int> numbers, int target) {
        int n=numbers.size();
        vector<int> ret;
        if(n<2) return ret;
        int left=0,right=n-1;
        while(left<right) {
            if(numbers[left]+numbers[right]>target) --right;
            else if(numbers[left]+numbers[right]<target) ++left;
            else {
                ret.push_back(left+1);
                ret.push_back(right+1);
                break;
            }
        }
        return ret;
    }
    
    static void test() {
        int n,x;
        Solution sol;
        vector<int> numbers;
        cin>>n;
        for(int i=0;i<n;++i) {
            cin>>x;
            numbers.push_back(x);
        }
        while(cin>>x) {
            vector<int> res=sol.twoSum(numbers,x);
            if(res.size()==0) cout<<"ans=null"<<endl;
            else cout<<"ans="<<res[0]<<","<<res[1]<<endl;   
        }
    }
};

