#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;

// optimization: 
// 1. if index[c]<start, there's no need to remove it from array/set/map;
// 2. if find dup, remove to the position where the conflict will be solved directly
// 3. map/set is much heavier than bitmap.

class Solution {
public:
    int lengthOfLongestSubstring(string s) { 
        int n = s.length();
        if (n == 0) return 0;

        int index[256];
        memset(index, -1, 256*sizeof(int));
        int len = 0, start = 0, ans = 1;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            int idx = index[c];
            if (idx >= start) {
                start = idx + 1;
                len = i - start;
            }
            ++len;
            index[c] = i;
            ans = max(ans, len);
        }

        return ans;
    }

    int lengthOfLongestSubstring2(string s) { // BF: very slow
        int n = s.length();
        if (n == 0) return 0;

        set<char> st;
        int i = 0, j = 0, ans = 1;
        while (j < n)
        {
            set<char>::iterator it = st.find(s[j]);
            if (it == st.end())
            {
                st.insert(s[j]);
                ++j;
                ans = max(ans, j-i);
            }
            else
            {
                st.erase(s[i]);
                ++i;
            }
        }

        return ans;
    }

    static void test() {
        string s;
        cin>>s;
        Solution sol;
        cout<<"result="<<sol.lengthOfLongestSubstring(s)<<endl;
    }
};