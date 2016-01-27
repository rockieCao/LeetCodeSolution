#include<iostream>
#include<vector>
using namespace std;

/*Problem: Factor Combinations
Numbers can be regarded as product of its factors. For example, 
8 = 2 x 2 x 2;
  = 2 x 4.


Write a function that takes an integer n and return all possible combinations of its factors. 

Note: 
1.Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2]. 
2.You may assume that n is always positive. 
3.Factors should be greater than 1 and less than n.

Solution: DFS
*/

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ret;
        vector<int> tmp;
        search(ret,tmp,n,2);
        return ret;
    }
    
    void search(vector<vector<int>> &res, vector<int> &cur, int n, int start) {
        if(n<2) {
            if(cur.size()>1) res.push_back(cur);
            return;
        }
        for(int i=start;i<=n;++i) {
            if(n%i==0) {
                cur.push_back(i);
                search(res,cur,n/i,i);
                cur.pop_back();
            }
        }
    }
    
    static void test() {
        int n;
        Solution sol;
        while(cin>>n) {
            vector<vector<int>> ret=sol.getFactors(n);
            cout<<"ans="<<endl;
            for(int i=0;i<ret.size();++i) {
                for(int j=0;j<ret[i].size();++j) {
                    cout<<ret[i][j]<<",";
                }
                cout<<endl;
            }
        }
    }
};

