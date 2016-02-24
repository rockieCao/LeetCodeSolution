#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int la=a.length(), lb=b.length();
        if (la==0) return b;
        if (lb==0) return a;
        string res="";
        int ia, ib, carry = 0;
        for(ia=la-1,ib=lb-1; ia>=0&&ib>=0; --ia,--ib) {
            int cur=(a[ia]-'0')+(b[ib]-'0')+carry;
            carry=cur/2;
            res = (char)('0'+(cur%2))+res;
        }
        while(ia>=0) {
            int cur=(a[ia]-'0')+carry;
            carry=cur/2;
            res = (char)('0'+cur%2)+res;
            --ia;   
        }
        while(ib>=0) {
            int cur=(b[ib]-'0')+carry;
            carry=cur/2;
            res = (char)('0'+cur%2)+res;
            --ib;   
        }
        while(carry>0) {
            int cur=carry%2;
            carry=carry/2;
            res = (char)('0'+cur)+res;   
        }
        return res;
    }
};
