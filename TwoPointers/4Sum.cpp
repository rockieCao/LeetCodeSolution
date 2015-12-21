#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// K-sum problem:
// can be reduced to 2-sum problem finally
// an O(n^2*logn) solution can refer to http://blog.csdn.net/linhuanmars/article/details/24826871
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) { // O(n^3)
        int n = num.size();
        vector<vector<int> > ans;
        if (n <= 3) return ans;
        
        sort(num.begin(), num.end());

        for (int i = 0; i < n-3; i++)
        {
            if (i>0&&num[i]==num[i-1]) continue;
            for (int j = i+1; j < n-2; j++)
            {
                if (j>i+1&&num[j]==num[j-1]) continue;
                int sum = target - num[i] - num[j];

                int l = j+1, r = n-1;
                while (l < r)
                {
                    if (l>j+1&&num[l]==num[l-1]) {
                        ++l;
                        continue;
                    }
                    int diff = num[l]+num[r]-sum;
                    if (diff == 0)
                    {
                        vector<int> t(4,0);
                        t[0]=(num[i]);
                        t[1]=(num[j]);
                        t[2]=(num[l]);
                        t[3]=(num[r]);
                        ans.push_back(t);
                        ++l;
                        --r;
                    }
                    else if (diff > 0)
                        --r;
                    else
                        ++l;
                }
            }
        }
        return ans;
    }

    vector<vector<int> > fourSum2(vector<int> &num, int target) { // worse than O(n^3)
        int n = num.size();
        vector<vector<int> > ans;
        if (n <= 3) return ans;
        
        sort(num.begin(), num.end());
        unordered_map<int, vector<pair<int,int> > > pairs;
        pairs.reserve(n*n);

        for (int i = 0; i < n-1; i++)
            for (int j = i+1; j < n; j++)
            {
                pairs[num[i]+num[j]].push_back(make_pair(i,j));
            }
        
        for (int i = 0; i < n-3; i++)
        {
            if (i>0&&num[i]==num[i-1]) continue;
            for (int j = i+1; j < n-2; j++)
            {
                if (j>i+1&&num[j]==num[j-1]) continue;
                int sum = target - num[i] - num[j];
                
                int nn = pairs[sum].size();
                if (nn > 0)
                {
                    int prev3rdElement;
                    bool first = true;
                    for (int k = 0; k < nn; k++)
                    {
                        pair<int,int> p = pairs[sum][k];
                        if (p.first <= j) continue;
                        if (first || prev3rdElement != num[p.first])
                        {
                            vector<int> t(4,0);
                            t[0]=(num[i]);
                            t[1]=(num[j]);
                            t[2]=(num[p.first]);
                            t[3]=(num[p.second]);
                            ans.push_back(t);
                            prev3rdElement = num[p.first];
                            first = false;
                        }
                    }
                }
            }
        }
        return ans;
    }

    static void test() {
        int n, target;
        cin>>n>>target;
        vector<int> num(n,0);
        for (int i = 0; i < n; i++)
            cin>>num[i];
        Solution sol;
        vector<vector<int> > res = sol.fourSum(num, target);
        for (vector<int> vec : res)
        {
            cout<<"{"<<vec[0]<<","<<vec[1]<<","<<vec[2]<<","<<vec[3]<<"}"<<endl;
        }
    }
};