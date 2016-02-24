#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        string units[]={""," Thousand", " Million", " Billion"};
        string ten[]={"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string hundred[]={"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string twenty[]={"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        
        int i=0;
        string res="";
        while(num>0) {
            int temp=num%1000;
            if(temp>0) {
                int x=temp/100;
                string hund="";
                if(x>0) {
                    hund = ten[x]+" Hundred";
                }
                x=temp%100;
                if(x>=10&&x<20) {
                    if(hund!="") hund+=" ";
                    hund+=twenty[x%10];
                }
                else if(x>=20) {
                    if(hund!="") hund+=" ";
                    hund+=hundred[x/10-1];
                }
                if(temp%10>0) {
                    if(hund!="") hund+=" ";
                    hund+=ten[temp%10];   
                }
                res = hund+units[i]+(res.length()==0?"":" "+res);
            }   
            num/=1000;
            ++i;
        }
        return res==""?ten[0]:res;
    }
};
