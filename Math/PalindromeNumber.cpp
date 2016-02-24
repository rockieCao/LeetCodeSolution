#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x<10) return true;
        int base = 1;
        while (x/base>=10) {
            base*=10;   
        }
        int remain=1;
        while(base>=remain) {
            if(x/base!=(x%(10*remain)/remain)) return false;
            x-=x/base*base;
            base/=10;
            remain*=10;
        }
        return true;
    }
};
