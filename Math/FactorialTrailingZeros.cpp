#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ret=0,five=5;
        while(n>=five) {
            ret+=n/five;
            if(n/5<five) break; //attention: prejudge to avoid overflow of five
            five*=5;   
        }
        return ret;
    }
};
