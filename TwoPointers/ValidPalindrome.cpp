#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0) return true;
        bool valid = true;
        int i = 0, j = s.length()-1;
        while (i<j)
        {
            if (isalnum(s[i])&&isalnum(s[j])) {
                if (tolower(s[i])!=tolower(s[j]))
                {
                    valid = false;
                    break;
                }
                i++;
                j--;
            }
            if (!isalnum(s[i])) ++i;
            if (!isalnum(s[j])) --j;
        }
        return valid;
    }

    static void test() {
        string s;
        cin>>s;
        
        Solution sol;
        cout<<"result="<<sol.isPalindrome(s)<<endl;
    }
};