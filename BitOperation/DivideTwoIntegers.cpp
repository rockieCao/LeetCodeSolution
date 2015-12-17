#include <iostream>
#include <cmath>
using namespace std;

/*
 * Boundary test case: -2147483648, -1
 * int range is [-2147483648, 2147483647]
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;

        long long x = abs((long long)dividend);
        long long y = abs((long long)divisor);
        long long res = 0LL;
        bool sign = ((dividend<0)^(divisor<0));
        bool overflow = false;

        while (x >= y)
        {
            long long temp = y;
            long long i = 1LL;
            while (x >= temp)
            {
                res += i;
                if ((!sign&&res>INT_MAX)||(sign&&res-1>INT_MAX))
                {
                    overflow = true;
                    break;
                }

                x -= temp;

                if (x < temp) break;
                temp<<=1;
                i<<=1;
            }
            if (overflow) break;
        }

        return overflow?INT_MAX:(sign?-res:res);
    }

    static void test()
    {
        int x, y;
        cin>>x>>y;
        Solution sol;
        cout<<"result="<<sol.divide(x,y)<<endl;
    }
};