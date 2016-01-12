#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfThree2(int n) {
        if (n<1||(n!=1&&n%3!=0)) return false;
        else return (int)pow(3.0, (int)(log10(n)/log10(3))) == n; //note: control precision is the key
    }
    
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        else if(n==0||n%3>0) return false;
        else return isPowerOfThree(n/3);
    }
    
    bool isPowerOfThree3(int n) {
        if(n==0) return false;
        while(n>1) {
            if(n%3!=0) return false;
            n/=3;
        }
        return true;
    }
    
    static void test() {
        Solution sol;
        int n;
        while(cin>>n)
            cout<<"ans="<<sol.isPowerOfThree2(n)<<endl;
    }
};

