#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rec;
    int numTrees(int n) {
        if (n <= 1) return 1;
        rec = vector<int>(n+1,-1);
        return search(n);
    }

    int search(int n) {
        if (n <= 1) return 1;
        if (rec[n] != -1) return rec[n];
        rec[n] = 0;
        for (int i = 1; i<=n; i++)
        {
            rec[i-1] = search(i-1);
            rec[n-i] = search(n-i);
            rec[n] += rec[i-1]*rec[n-i];
        }
        return rec[n];
    }

    static void test() {
        int n;
        cin>>n;
        cout<<Solution().numTrees(n)<<endl;
    }
};