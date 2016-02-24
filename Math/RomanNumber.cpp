#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.length(), ret=0;
        for(int i=0;i<n;++i)
            ret+=parseDigit(s[i]);
        for(int i=1;i<n;++i) {
            int pre=parseDigit(s[i-1]);
            int cur=parseDigit(s[i]);
            if((pre*5==cur)||(pre*10==cur))
                ret-=2*pre;   
        }
        return ret;
    }
    
    int parseDigit(char c) {
        int ret=0;
        switch(c) {
            case 'I': ret=1; break;
            case 'V': ret=5; break;
            case 'X': ret=10; break;
            case 'L': ret=50; break;
            case 'C': ret=100; break;
            case 'D': ret=500; break;
            case 'M': ret=1000; break;
        }   
        return ret;
    }
};
