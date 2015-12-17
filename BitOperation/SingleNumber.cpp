#include<iostream>
using namespace std;

//Given an array of integers, every element appears twice except for one. Find that single one. 
class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n==1) return A[0];
        int ans = A[0];
        for (int i = 1; i < n; i++)
            ans ^= A[i];
        return ans;
    }
};