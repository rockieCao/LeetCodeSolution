#include<iostream>
using namespace std;

//Given an array of integers, every element appears three times except for one. Find that single one. 
class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n==1) return A[0];

        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int tmp = 0;
            for (int j = 0; j < n; j++)
            {
                tmp += ((A[j]>>i)&1);
            }
            ans <<=1;
            ans |= tmp%3;
        }

        return ans;
    }

    static void test() {
        int n;
        cin>>n;
        int A[100];
        for (int i = 0; i < n; i++)
            cin>>A[i];
        Solution sol;
        cout<<"result="<<sol.singleNumber(A, n)<<endl;
    }
};