#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Problem: find longest consecutive sequence from an unordered array. need O(n) algo.
//Use hash set as data structure for search element, and for each elem, enumerate elems less then it and also elems greater than it.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;

        unordered_map<int, bool> set;
        int ans = 1;
        for (int elem : nums)
        {
            set[elem] = false;
        }

        for (int i = 0; i < sz; i++)
        {
            if (set[nums[i]] == true) continue;

            int start = nums[i]-1, end = nums[i]+1, cnt = 1;
            set[nums[i]] = true;
            while (set.find(start)!=set.end())
            {
                set[start]=true;;
                --start;
                ++cnt;
            }
            while (set.find(end)!=set.end())
            {
                set[end]=true;
                ++end;
                ++cnt;
            }
            if (cnt>ans)
                ans = cnt;
        }

        return ans;
    }
};