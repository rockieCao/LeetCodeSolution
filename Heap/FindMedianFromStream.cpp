#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

//维护一个大根堆保存较小的数，另一个小根堆保存较大的数

class MedianFinder {
public:
    vector<int> vec1, vec2;

    // Adds a number into the data structure.
    void addNum(int num) {
        if (vec1.empty()) {
            vec1.push_back(num);
            make_heap(vec1.begin(), vec1.end(), less<int>()); // big root
            vec2.push_back(num);
            make_heap(vec2.begin(), vec2.end(), greater<int>());
            pop_heap(vec2.begin(), vec2.end(), greater<int>());
            vec2.pop_back();
        }
        else {
            if (vec1.size()-vec2.size()==0) {
                int tmp2 = vec2[0];
                if (num<=tmp2) {
                    vec1.push_back(num);
                    push_heap(vec1.begin(), vec1.end());
                }
                else {
                    pop_heap(vec2.begin(), vec2.end(), greater<int>());
                    vec2.pop_back();
                    vec2.push_back(num);
                    push_heap(vec2.begin(), vec2.end(), greater<int>());
                    vec1.push_back(tmp2);
                    push_heap(vec1.begin(), vec1.end());
                }
            }
            else {
                int tmp1 = vec1[0];
                cout<<"tmp1="<<tmp1<<endl;
                if (num<tmp1) {

                    pop_heap(vec1.begin(), vec1.end());
                    vec1.pop_back();
                    vec1.push_back(num);
                    push_heap(vec1.begin(), vec1.end());
                    vec2.push_back(tmp1);
                    /*if (vec2.size()==1)
                        make_heap(vec2.begin(), vec2.end(), greater<int>());
                    else*/
                    push_heap(vec2.begin(), vec2.end(), greater<int>());
                }
                else {
                    vec2.push_back(num);
                    /*if (vec2.size()==1)
                        make_heap(vec2.begin(), vec2.end(), greater<int>());
                    else*/
                        push_heap(vec2.begin(), vec2.end(), greater<int>());
                }
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int n1 = vec1.size(), n2 = vec2.size();
        if ((n1+n2)%2==1) {
            return vec1[0];
        }
        else {
            return 0.5*(vec1[0]+vec2[0]);
        }
    }
};

class Solution {
public:
    static void test() {
        MedianFinder mf;
        mf.addNum(-1);
        cout<<"median="<<mf.findMedian()<<endl;
        mf.addNum(-2);
        cout<<"median="<<mf.findMedian()<<endl;
        mf.addNum(-3);
        cout<<"median="<<mf.findMedian()<<endl;
        mf.addNum(-4);
        cout<<"median="<<mf.findMedian()<<endl;
        mf.addNum(-5);
        cout<<"median="<<mf.findMedian()<<endl;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();