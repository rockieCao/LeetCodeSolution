#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            if (len>0&&A[i] == A[len-1])
                continue;
            A[len++] = A[i];
        }
        return len;
    }

    // duplicates are allowed at most twice
    int removeDuplicates2(int A[], int n) {
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            if (len>1&&A[i] == A[len-1] && A[i] == A[len-2])
                continue;
            A[len++] = A[i];
        }
        return len;
    }
};