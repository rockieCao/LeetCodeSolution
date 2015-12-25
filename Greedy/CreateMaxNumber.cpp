#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Problem: Create Max Number
Given two arrays of length m and n with digits 0-9 representing two numbers. 
Create the maximum number of length k <= m + n from digits of the two. 
The relative order of the digits from the same array must be preserved. 
Return an array of the k digits. You should try to optimize your time and space complexity. 

Solution: break the problem into two part:
1) given x, how to pick x elements out of an array so that it can form the largest number with relative order reserved. O(N)
2) for each pair (x,k-x), get largest sequence from two arrays A and B, how to interleave them to get larget numbers. O(N^2)
   Gready algorithm: for two sequence sa and sb, if sa+sb>sb+sa, then output sa first.
                     here, when enumerate element in array, compare out[len-1] with array[cur].

Test cases:
4 6 5
3 4 6 5
9 1 2 5 8 3

2 3 5
6 7
6 0 4

2 2 3
3 9
8 9

0 1 1
1

6 6 6
3 4 8 9 3 0
6 1 9 1 1 2
*/

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) { //
        int n=nums1.size(), m=nums2.size();
        int nn=min(n,k), mm=min(m,k);
        
        vector<int> ret(k,0);
        for(int i=max(0,k-mm);i<=nn;++i) {
            int j=k-i;
            vector<int> cand1(i,0), cand2(j,0);
            selection(nums1,i,cand1);
            selection(nums2,j,cand2);
            
            int ii=0,jj=0,kk=0;
            vector<int> tmp(k,0);
            while(ii<i||jj<j) {
                if(comp(cand1,ii,cand2,jj)) tmp[kk]=cand1[ii++];
                else tmp[kk]=cand2[jj++];
                ++kk;
            }
            
            if(comp(tmp,0,ret,0)) {
                ret=tmp;
            }
        }
        return ret;
    }
    
    void selection(vector<int> nums, int m, vector<int>& out) {
        int cnt=0, n=nums.size();
        for(int i=0;i<n;++i) {
            while(cnt>0&&cnt+n-i>m&&nums[i]>out[cnt-1])
                --cnt;
            if(cnt<m)
                out[cnt++]=nums[i];
        }
    }
    
    bool comp(vector<int> va, int sa, vector<int> vb, int sb) {
        int na=va.size(), nb=vb.size();
        while(sa<na&&sb<nb) {
            if(va[sa]>vb[sb]) return true;
            else if(va[sa]<vb[sb]) return false;
            ++sa;
            ++sb;
        }
        return sa<na;
    }
        
    void show(vector<int> vec) {
        for(auto a:vec) cout<<a<<",";
    }
    
    static void test() {
        int n,m,k;
        Solution sol;
        while(cin>>n>>m>>k) {
            vector<int> nums1(n,0);
            vector<int> nums2(m,0);
            for(int i=0;i<n;++i) {
                cin>>nums1[i];
            }
            for(int i=0;i<m;++i) {
                cin>>nums2[i];
            }
            
            vector<int> ret=sol.maxNumber(nums1, nums2, k);
            cout<<"ans=[";
            for(int i=0;i<ret.size();++i)
                cout<<ret[i]<<",";
            cout<<"]"<<endl;
        }
    }
};
