#include<iostream>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) 
    {
        int red = 0, white = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == 0) ++red;
            if (A[i] == 1) ++white;
        }
        for (int i = 0; i < n; i++)
        {
            if (red > 0) { A[i] = 0; --red; }
            else if (white > 0) { A[i] = 1; --white; }
            else { A[i] = 2; }
        }
    }

    void sortColors2(int A[], int n) // not general
    {
        int tail = n-1;
        int head = 0;
        for (int i = 0; i <= tail;)
        {
            if (A[i] == 0)
            {
                swap(A, i, head);
                ++head;
                ++i;
            }
            else if (A[i] == 2)
            {
                swap(A, i, tail);
                --tail;
            }
            else
                ++i;
        }
    }

    void swap(int A[], int i, int j)
    {
        if (i == j) return;
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }

    static void test()
    {
        int n, x;
        cin>>n;
        int *A = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin>>A[i];
        }
        Solution sol;
        sol.sortColors2(A, n);
        for (int i = 0; i < n; i++)
        {
            cout<<A[i]<<",";
        }
        cout<<endl;

        delete[] A;
    }
};