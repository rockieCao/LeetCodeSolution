#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x, ret = 0;
        while(n>0) {
            x=n&(~(n-1));
            n^=x;
            ++ret;   
        }
        return ret;
    }
}; 
