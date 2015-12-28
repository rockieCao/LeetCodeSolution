#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n==0) return 0;
        stack<int> st;
        int start = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i]=='(') {
                st.push(i);
            }   
            else {
                if (st.empty()) {
                    start = i+1;   
                }
                else {
                    st.pop();
                    if (st.empty()) {
                        ans = max(ans, i-start+1);   
                    }
                    else {
                        ans = max(ans, i-st.top());
                    }
                }
            }
        }
        return ans;
    }
};
