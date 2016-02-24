#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sa=0, la=str.length();
        if(la==0) return 0;
        while(sa<la-1&&(str[sa]==' '||str[sa]=='0')) {
            ++sa;
        }
        str=str.substr(sa,la-sa);
        la=la-sa;
        bool positive=true;
        sa=0;
        if(str[0]=='-') {
            positive=false; ++sa;
        }
        else if(str[0]=='+') ++sa;
        else if(!isdigit(str[0])) return 0;
        
        long long res=0;
        for(int i=sa; i<la; ++i) {
            if(!isdigit(str[i])) break;
            res = res*10+(str[i]-'0');
            if(positive&&res>INT_MAX) return INT_MAX;
            else if(!positive&&-res<INT_MIN) return INT_MIN;
        }
        return positive?(int)res:(int)-res;
    }
};
