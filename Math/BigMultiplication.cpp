#include <iostream>
#include <string>
using namespace std;

// big number add/multiply
class Solution {
public:
    string multiply(string num1, string num2) {
        int la=num1.length(), lb=num2.length();
        int sa=0, sb=0;
        while(sa<la-1&&num1[sa]=='0') {
            ++sa;
        }
        while(sb<lb-1&&num2[sb]=='0') {
            ++sb;   
        }
        num1=num1.substr(sa,la-sa);
        num2=num2.substr(sb,lb-sb);
        la=la-sa;
        lb=lb-sb;
        if(la==0||lb==0||(la==1&&num1[0]=='0')||(lb==1&&num2[0]=='0')) return "0";
        if(la==1&&num1[0]=='1') return num2;
        if(lb==1&&num2[0]=='1') return num1;
        
        string res="0";
        string zeros="";
        int carry=0;
        for(int i=la-1; i>=0; --i, zeros+="0") {
            string val=zeros;
            carry=0;
            for(int j=lb-1; j>=0; --j) {
                int cur=(num1[i]-'0')*(num2[j]-'0')+carry;
                val = (char)('0'+cur%10)+val;
                carry=cur/10;
            }
            if(carry>0) val = (char)('0'+carry)+val;
            res=add(res, val);
        }
        return res;
    }
    
    string add(string num1, string num2) {
        int la=num1.length(), lb=num2.length();
        int carry=0;
        string res="";
        while(la>0&&lb>0) {
            int cur=(num1[la-1]-'0')+(num2[lb-1]-'0')+carry;
            res=(char)('0'+cur%10)+res;
            carry=cur/10;
            --la;
            --lb;
        }
        while(la>0) {
            int cur=(num1[la-1]-'0')+carry;
            res=(char)('0'+cur%10)+res;
            carry=cur/10;
            --la;   
        }
        while(lb>0) {
            int cur=(num2[lb-1]-'0')+carry;
            res=(char)('0'+cur%10)+res;
            carry=cur/10;
            --lb;   
        }
        if(carry>0) {
            res=(char)('0'+carry)+res;   
        }
        return res;
    }
    
    string multiply2(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if ("0"==num1||"0"==num2) {
            return "0";   
        }   
        string result = "";
        int carry=0, zeros=0;
        for(int i=0; i<num1.length(); ++i) {
            int pos=zeros;
            carry=0;
            for(int j=0; j<num2.length(); ++j) {
                int cur=(num1[i]-'0')*(num2[j]-'0')+carry;
                if(pos<result.length()) {
                    cur+=result[pos]-'0';
                    result[pos]=(cur%10)+'0';   
                } 
                else {
                    result.append(1, (cur%10)+'0');   
                }
                carry=cur/10;
                ++pos;
            }   
            if(carry>0) {
                result.append(1, carry+'0');   
            }
            ++zeros;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
