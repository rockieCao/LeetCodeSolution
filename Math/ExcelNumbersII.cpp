#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res="";
        while(n>0) {
            res.append(1, 'A'+(n%26+25)%26);
            n=(n-1)/26;   
        }
        reverse(res.begin(),res.end());
        return res;      
    }
};
