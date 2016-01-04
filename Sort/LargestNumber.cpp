#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(const string& a, const string& b)
    {
        string ab=a+b, ba=b+a;
        return ab>ba;
    }

    string largestNumber(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return "0";

        vector<string> strs;
        strs.reserve(sz);

        for (int i = 0; i < sz; i++)
        {
            int x = nums[i];
            if (x == 0) { strs.push_back("0"); continue; }
            string s = "";
            while (x>0)
            {
                s=char('0'+x%10)+s;
                x/=10;
            }
            strs.push_back(s);
        }

        sort(strs.begin(), strs.end(), cmp);

        string ans = "";
        for (int i = 0; i < sz; i++)
        {
            ans += strs[i];
        }

        // Attention: need to handle prefix zeros
        int nonZero = 0;
        while (nonZero+1 < ans.length() && ans[nonZero]=='0') ++nonZero;
        ans = ans.substr(nonZero);

        return ans;
    }

    static void test() 
    {
        int n;
        cin>>n;
        int x;
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            vec.push_back(x);
        }
        Solution sol;
        cout<<"ans = "<<sol.largestNumber(vec)<<endl;
    }
};