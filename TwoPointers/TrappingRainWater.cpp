#include<iostream>
#include<vector>
using namespace std;

//solution:维护一个长度为n的数组，进行两次扫描，一次从左往右，一次从右往左。
//第一次扫描的时候维护对于每一个bar左边最大的高度是多少，存入数组对应元素中，
//第二次扫描的时候维护右边最大的高度，并且比较将左边和右边小的最大高度（我们成为瓶颈）存入数组对应元素中。
//这样两遍扫描之后就可以得到每一个bar能承受的最大水量，从而累加得出结果。
//similar problem:http://oj.leetcode.com/problems/candy/

class Solution {
public:
    int trap(int A[], int n) {
         vector<int> left(n,0), right(n,0);
         int mmax = A[0], ans = 0;
         for (int i = 1; i <= n-2; i++)
         {
             left[i] = mmax;
             if (A[i] > mmax) mmax = A[i];
         }
         mmax = A[n-1];
         for (int i = n-2; i >= 1; i--)
         {
             right[i] = mmax;
             if (A[i] > mmax) mmax = A[i];
             int mmin = min(left[i], right[i]);
             if (mmin > A[i])
                 ans += mmin - A[i];
         }
         return ans;
    }

    //two pointers optimize
    int trap2(int A[], int n) {
        int left = 0, right = n-1, ans = 0, mmin = 0;
        while (left < right)
        {
            if (A[left]<=A[right])
            {
                mmin = A[left];
                left++;
                while (left < right && A[left]<mmin)
                {
                    ans+= mmin-A[left];
                    ++left;
                }
            }
            else
            {
                mmin = A[right];
                right--;
                while (left < right && A[right]<mmin)
                {
                    ans+= mmin-A[right];
                    --right;
                }
            }
        }

        return ans;
    }

    static void test()
    {
        int n, x;
        cin>>n;
        int *A = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin>>A[i];
        }
        Solution sol;
        cout<<"result="<<sol.trap(A, n)<<endl;

        delete[] A;
    }
};