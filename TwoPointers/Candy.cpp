#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> cand(n, 0);
        cand[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i]>ratings[i-1]) cand[i]=cand[i-1]+1;
            else cand[i]=1;
        }
        int sum = cand[n-1];
        for (int i = n-2; i>=0; i--)
        {
            if (ratings[i]>ratings[i+1]) cand[i]=max(cand[i], cand[i+1]+1);
            sum += cand[i];
        }
        return sum;
    }

    static void test() {
        int n;
        cin>>n;
        vector<int> ratings(n,0);
        for (int i = 0; i < n; i++)
        {
            cin>>ratings[i];
        }
        Solution sol;
        cout<<"result="<<sol.candy(ratings)<<endl;
    }
};