#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) { // O(n^2)
        if (num.size() <= 2) return INT_MIN;
        int closest = abs(num[0]+num[1]+num[2]-target);
        int sum = num[0]+num[1]+num[2];
        int sz = num.size();
        sort(num.begin(), num.end());
        
        for (int i = 0; i < sz; ++i)
        {
            //two sum
            int t = target - num[i];
            int l = i+1;
            int r = sz-1;
            while (l < r)
            {
                int diff = abs(t-num[l]-num[r]);
                if (diff<closest) {
                    closest = diff;
                    sum = num[i]+num[l]+num[r];
                }
                if (diff==0)
                {
                    break;
                }
                else if (num[l]+num[r]>t)
                    --r;
                else
                    ++l;
            }
            if (closest == 0) break;
        }

        return sum;
    }

    static void test() {
        int n,x;
        cin>>n>>x;
        vector<int> num(n,0);
        for(int i = 0; i < n; i++)
            cin>>num[i];
        Solution sol;
        cout<<"result="<<sol.threeSumClosest(num, x)<<endl;
    }
};