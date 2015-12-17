#include <iostream>
#include <string>
using namespace std;

/*
Problem:
    Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
    For example, given the range [5, 7], you should return 4. 
Solution:
    from high bit to low bit, if current bit in m and n are same, then the bit in final result will be same as m also.
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m==n) return m;
        int ret = 0;
        for(int i=31; i>=0; --i) {
            uint32_t mask=(1u<<i);
            if((m&mask)==(n&mask)) {
                ret |= (m&mask);   
            }
            else break;
        }
        return ret;
    }
};
