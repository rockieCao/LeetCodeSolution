#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int n = num.size();
        vector<vector<int> > ans;
        if (n < 3) return ans;

        sort(num.begin(), num.end());

        for (int i = 0; i < n-2; i++)
        {
            if (i>0&&num[i]==num[i-1]) continue;
            int sum = 0-num[i];
            int l = i+1, r = n-1;
            while (l < r)
            {
                if (l>i+1&&num[l]==num[l-1])
                {
                    ++l;
                    continue;
                }
                int diff = sum-num[l]-num[r];
                if (diff == 0)
                {
                    vector<int> t(3,0);
                    t[0]=num[i];
                    t[1]=num[l];
                    t[2]=num[r];
                    ans.push_back(t);
                    ++l;
                    --r;
                }
                else if (diff > 0)
                {
                    ++l;
                }
                else
                    --r;
            }
        }
        return ans;
    }

    static void test() {
        int n;
        cin>>n;
        vector<int> num(n,0);
        for (int i = 0; i < n; i++)
            cin>>num[i];
        Solution sol;
        vector<vector<int> > res = sol.threeSum(num);
        for (vector<int> vec : res)
        {
            cout<<"{"<<vec[0]<<","<<vec[1]<<","<<vec[2]<<"}"<<endl;
        }
    }
};