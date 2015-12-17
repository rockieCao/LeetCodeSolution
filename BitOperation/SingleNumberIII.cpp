#include <iostream>
#include <string>
#include <vector>
using namespace std;

//优化：result & (~(result-1)) 即可找到右起第一个为1的位 

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        
        int xorx = 0;
        for(int i=0;i<n;++i) {
            xorx ^= nums[i];   
        }
        for(int i=31;i>=0;--i) {
            if((xorx>>i)&1) { //找到不同的位，将原数组划分为两部分，则问题变为分别在两个数列中找只出现1次的数。 
                int xor0 = 0, xor1 = 0;
                for(int j=0;j<n;++j) {
                    int x=nums[j];
                    if((x>>i)&1) {
                        xor1 ^= x;   
                    }
                    else {
                        xor0 ^= x;   
                    }   
                }
                ret.push_back(xor0);
                ret.push_back(xor1);
                break;   
            }
        }
        return ret;
    }
};
