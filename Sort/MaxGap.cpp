#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/***
 * Pigeonhole Princle
 * Suppose there are N elements and they range from A to B.
 * Then the maximum gap will be no smaller than ceiling[(B - A) / (N - 1)]
 * Let the length of a bucket to be len = ceiling[(B - A) / (N - 1)], then we will have at most num = (B - A) / len + 1 of bucket
 * --> Except global max and min value, there's N-2 elements to be placed into N-1 or N buckets, i.e. there must be at least one empty bucket.
 * for any number K in the array, we can easily find out which bucket it belongs by calculating loc = (K - A) / len and therefore maintain the maximum and minimum elements in each bucket.
 * Since the maximum difference between elements in the same buckets will be at most len - 1, so the final answer will not be taken from two elements in the same buckets
 * For each non-empty buckets p, find the next non-empty buckets q, then q.min - p.max could be the potential answer to the question. Return the maximum of all those values.
***/

class Solution {
public:
    int maximumGap(vector<int>& nums) { // O(N)
        int sz = nums.size();
        if (sz < 2) return 0;
        
        int mmax=nums[0], mmin=nums[0];

        for (int i = 1; i < sz; i++)
        {
            if (nums[i]<mmin) mmin = nums[i];
            if (nums[i]>mmax) mmax = nums[i];
        }

        double range = mmax - mmin;
        int bucketSZ = ceil(range/(sz-1));
        int bucketCnt = ceil(range/bucketSZ);
        vector< pair<int,int> > buckets(bucketCnt, make_pair(INT_MIN, INT_MAX)); //max, min value for each bucket
        for (int i = 0; i < sz; i++)
        {
            if (nums[i] == mmax || nums[i] == mmin) continue;
            int id = (nums[i] - mmin)/bucketSZ;
            if (nums[i] > buckets[id].first)
                buckets[id].first = nums[i];
            if (nums[i] < buckets[id].second)
                buckets[id].second = nums[i];
        }

        int maxGap = 0, preMax = mmin;
        for (int i = 0; i < bucketCnt; i++)
        {
            if (buckets[i].first == INT_MIN) continue; //empty
            maxGap = max(maxGap, buckets[i].second-preMax);
            preMax = buckets[i].first;
        }

        maxGap = max(maxGap, mmax - preMax);
        return maxGap;
    }

    static void test()
    {
        int n,x;
        vector<int> vec;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            vec.push_back(x);
        }

        Solution sol;
        cout<<"result is :"<<sol.maximumGap(vec)<<endl;
    }
};