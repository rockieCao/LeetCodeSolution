#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*
推导过程：枚举n=10的例子，发现灯i的开关次数为i的所有因子的个数，设i的质因数分解为p0^a0 * p1^a1 * p2^a2 * ... * pk^ak，那么所有因子的个数为(1+a0)*（1+a1)*...
结合本题：实际只关心因子数为奇数的i的个数，即所有ak都是偶数的情况，等价于不超过n的平方数的个数，最后即(int)sqrt(n) 
*/
class Solution {
public:
    vector<int> prim;
    int primCnt;
    
    void table(int n) {
        prim = vector<int>(n+1,0);
        primCnt = 0;
        for(int i=2;i<=n;++i) {
            if(prim[i]==0) prim[primCnt++]=i;
            for(int j=0;j<primCnt&&prim[j]<=n/i;++j) {
                prim[prim[j]*i]=1;
                if(i%prim[j]==0) break;   
            }
        }
    }
    
    int bulbSwitch2(int n) {
        if(n==0) return 0;
        if(n==1) return n;
        
        table(n);
        int ret=1;
        for(int i=2;i<=n;++i) {
            int j, cnt=1, tmpi=i;
            for(j=0;prim[j]*prim[j]<=tmpi;++j) {
                if(tmpi%prim[j]==0) {
                    int tmp=0;
                    while(tmpi>1&&tmpi%prim[j]==0) {
                        ++tmp;
                        tmpi/=prim[j];
                    }
                    if(tmp%2==1) { cnt=2; break; } // optimization: only cares odd and even
                    else cnt=3;
                    //cnt*=(tmp+1); //cnt represents the number of factors for i
                }
            }
            if(tmpi>1) cnt*=(1+1);
            if(cnt>1)
                ret+=cnt%2;
        }
        return ret;
    }
    
    int bulbSwitch(int n) { //final reduction
        return (int)sqrt(n);
    }
};

