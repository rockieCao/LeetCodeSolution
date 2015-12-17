#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ret = 0;
        for(int i=0; i<32; ++i) {
            ret = ((ret<<1)|(n&1));
            n>>=1;
        }
        return ret;
    }
};
