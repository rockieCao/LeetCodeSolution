/*
  Name: Find median from data stream
  Algorithm: max,minheap
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class MedianFinder {
public:
    vector<int> minHeap, maxHeap;
    // Adds a number into the data structure.
    void addNum(int num) {
        if (((maxHeap.size()+minHeap.size())&1) == 0) {
            if (maxHeap.size()>0&&num<maxHeap[0]) {
                maxHeap.push_back(num);
                push_heap(maxHeap.begin(), maxHeap.end(), less<int>());   
                
                num = maxHeap[0];
                pop_heap(maxHeap.begin(), maxHeap.end(), less<int>());
                maxHeap.pop_back();
            }
            
            minHeap.push_back(num);
            push_heap(minHeap.begin(), minHeap.end(), greater<int>());
        }
        else {
            if (minHeap.size()>0&&minHeap[0]<num)
            {
                minHeap.push_back(num);
                push_heap(minHeap.begin(), minHeap.end(), greater<int>());
                
                num = minHeap[0];
                
                pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
                minHeap.pop_back();
            }
            maxHeap.push_back(num);
            push_heap(maxHeap.begin(), maxHeap.end(), less<int>());   
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int size = minHeap.size()+maxHeap.size();
        if (size == 0) return -1;
        double median = 0; // note the type of return value
        if (size&1==1) median = minHeap[0];
        else median = (minHeap[0]+maxHeap[0])/2.0;
        return median;
    }
};

class Solution
{
public:
    static void test() {
        MedianFinder mf;
        string op;
        int x;
        while(cin>>op>>x) {
            if (op=="q") break;
            else if (op=="i") mf.addNum(x);
            else cout<<"median="<<mf.findMedian()<<endl;   
        }   
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

