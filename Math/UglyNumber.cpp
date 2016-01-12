#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num==0) return false;

        while (num>1&&(num%2==0))
            num>>=1;
        while (num>1&&(num%3==0))
            num/=3;
        while (num>1&&(num%5==0))
            num/=5;
        return num==1;
    }
};