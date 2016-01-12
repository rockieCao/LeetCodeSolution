#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int nthUglyNumber2(int n) {
        if (n==1) return 1;
        queue<int> q2, q3, q5;
        q2.push(2);
        q3.push(3);
        q5.push(5);

        int ans = 1;
        while (--n>0) {
            ans = min(q2.front(), min(q3.front(), q5.front()));

            if (ans==q2.front()) q2.pop();
            if (ans==q3.front()) q3.pop();
            if (ans==q5.front()) q5.pop();

            q2.push(2*ans);
            q3.push(3*ans);
            q5.push(5*ans);
        }

        return ans;
    }

    int nthUglyNumber(int n) { // only record the pointer
        int *arr = new int[n];
        arr[0] = 1;
        int p2=0, p3=0, p5=0;
        int sz = 1, ans = 1, ans2, ans3, ans5;
        while (sz < n) {
            ans2 = arr[p2]*2;
            ans3 = arr[p3]*3;
            ans5 = arr[p5]*5;
            ans = min(ans2,min(ans3,ans5));
            
            if (ans == ans2) ++p2;
            if (ans == ans3) ++p3;
            if (ans == ans5) ++p5;

            ++sz;
        }

        return ans;
    }
};