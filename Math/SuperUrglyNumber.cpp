#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//维护一个数组记录各个prime因子的乘数位置
//每次计算各个prime再乘一次得到的最小值，然后根据将所有能得到这个最小值的因子的乘数位置+1 

class Solution {
public:
    struct Node {
        int val,exponent,prim;
        Node(int _val,int _exponent, int _prim):val(_val),exponent(_exponent),prim(_prim){}
        inline bool operator <(const Node& other) const {
            return val<other.val;    
        }
    };
    
    int nthSuperUglyNumber(int n, vector<int>& primes) { //O(nlogn) 
        if(n==1) return 1;
        int primeCnt = primes.size();
        vector<int> ans(1,1);
        priority_queue<Node> pq;
        for(int i=0;i<primeCnt;++i)
            pq.push(Node(primes[i],0,primes[i]));
        int sz=1;    
        while (sz<n) {
            Node cur=pq.top();    
            ans.push_back(cur.val);
            while (!pq.empty()&&pq.top().val==cur.val) {
                Node tmp=pq.top();
                pq.pop();
                ++tmp.exponent;
                tmp.val = ans[tmp.exponent]*tmp.prim;
                pq.push(tmp);
            }
            ++sz;
        }
        return ans.back();
    }
    
    int nthSuperUglyNumber2(int n, vector<int>& primes) {//O(n)
        if(n==1) return 1;
        int primeCnt = primes.size();
        vector<int> arr;
        arr.push_back(1);
        vector<int> index(primeCnt,0);
        int sz=1;
        while(sz<n) {
            int mmin=arr[index[0]]*primes[0];
            int mminIndex = 0;
            vector<int> indexs(1,0);
            for(int i=1;i<primeCnt;++i) {
                int tmp=arr[index[i]]*primes[i];
                if(tmp<mmin) {
                    mmin=tmp;
                    mminIndex=i;
                    indexs.clear();
                    indexs.push_back(mminIndex);
                }
                else if(tmp==mmin) {
                    indexs.push_back(i);    
                }
            }
            arr.push_back(mmin);
            for(int idx:indexs) {
                index[idx]++;
            }
            ++sz;
            cout<<"debug:"<<arr.back()<<endl;
        }
        return arr.back();
    }
};
