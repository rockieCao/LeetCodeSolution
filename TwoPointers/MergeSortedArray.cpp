#include<iostream>
#include<algorithm>
using namespace std;

//如果要求不适用额外空间，则可以重用A的空间，先用尾部空闲的部分，用完以后，从头开始重用空间
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = 0, j = 0, k = m;
        while (i < m || j < n)
        {
            if (k == m+n) // 循环利用A的空间
                k = 0;
            if (i == m) A[k++]=B[j++];
            else if (j == n)  A[k++]=A[i++];
            else if (A[i]<=B[j]) A[k++]=A[i++];
            else A[k++]=B[j++];
        }

        reverse(A, A+m);
        reverse(A+m, A+m+n);
        reverse(A, A+m+n);
    }
};