#include <iostream>
#include <string>
using namespace std;

//A->1,Z->26,AA->27,BA->53

class Solution {
public:
    int titleToNumber(string s) {
        int ret=0, n=s.length();
        for(int i=0; i<n; ++i) {
            int x=s[i]-'A'; 
            ret=ret*26+x+1;
        }
        return ret;
    }
};
