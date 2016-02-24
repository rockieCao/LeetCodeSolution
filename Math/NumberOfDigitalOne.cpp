#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;
        if(n<10) return 1;
        int base=1;
        while((long long)base*10<=n) base*=10; // use long long to avoid overflow in the process
        int res = 0, cur, high, low;
        while(base>0) {
            cur=(n/base)%10;
            high=n/base/10; //当前位以前的 
            low=n%base; //当前位以后的 
            if (cur==1) {
                if (base>1) { //当前不是最低位时 
                    res += low+1;
                    if(base*10<=n) //当前不是最高位时 
                        res += high*base;
                }
                else //当前位是个位时 
                    res += high+1;
            }
            else if (cur<1) {
                res += high*base;
            }
            else if (cur>1) {
                res += (high+1)*base;   
            }
            base/=10;
        }
        return res;
    }
};
