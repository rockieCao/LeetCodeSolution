#include<iostream>
#include<vector>
using namespace std;

// 贪心算法：双指针，一前一后，每次移动height低的。
class Solution {
public:
    int maxArea2(vector<int> &height) {
        int res = 0, n = height.size();
        int mmax = 0;
        for (int i = 0; i < n; i++)
        {
            if (mmax < height[i]) {
                mmax = height[i];
                continue;
            }
            for (int j = 0; j < i; j++)
            {
                if (height[j]<height[i]) continue;
                res = max(res, height[i]*(i-j));
                break;
            }
        }
        mmax = 0;
        for (int i = n-1; i >= 0; i--)
        {
            if (mmax < height[i]) {
                mmax = height[i];
                continue;
            }

            for (int j = n-1; j > i; j--)
            {
                if (height[j]<height[i]) continue;
                res = max(res, height[i]*(j-i));
                break;
            }
        }

        return res;
    }

    int maxArea(vector<int> &height) {
        int res = 0, n = height.size();
        int i = 0, j = n-1;
        while (i < j)
        {
            int area = (j-i)*min(height[i], height[j]);
            res = max(res, area);

            if (height[i]<=height[j])
                i++;
            else
                j--;
        }

        return res;
    }

    static void test()
    {
        int n,x;
        cin>>n;
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            vec.push_back(x);
        }

        Solution sol;
        cout<<"result="<<sol.maxArea(vec)<<endl;
    }
};