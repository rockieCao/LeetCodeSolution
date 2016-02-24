#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        else return (num%9==0)?9:num%9;
    }
};
