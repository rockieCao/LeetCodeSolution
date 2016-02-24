#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        static string dict[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        static int value[]={1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};
        string ans="";
        int i=0;
        while(num!=0) {
            while(num>=value[i]) {
                num-=value[i];
                ans+=dict[i];
            }
            ++i;
        }
        return ans;
    }
};
