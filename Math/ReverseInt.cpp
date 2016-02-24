#include<iostream>
#include<string>
using namespace std;

//Note: the final result may overflow int type.
// when check intermediate result, need to convert to long long for INT_MIN to avoid overflow in the process
class Solution {
public:
    int reverse(int x) {
        if(x==0) return x;
        bool positive=true;
        if(x<0) { positive=false; x=-x; }
        int res = 0;
        while(x>0) {
            if ((positive&&(INT_MAX-x%10)/10<res)||(!positive&&((long long)INT_MIN-x%10)/10>-res)) return 0;
            res=res*10+x%10;
            x/=10;   
        }
        return positive?res:-res;
    }
};
