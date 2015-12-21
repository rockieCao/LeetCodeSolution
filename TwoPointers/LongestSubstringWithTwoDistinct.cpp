#include<iostream>
#include<map>
using namespace std;

/* Problem:
 * Longest Substring with At Most Two Distinct Characters
 * Description:
 * Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
 * For example, Given s = 揺ceba?
 * T is "ece" which its length is 3.
 */
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) { // O(n)
        map<char, int> mp; // ch->last appearance
        int ans = 0, start = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (mp.find(ch) == mp.end() && mp.size() == 2) {
                char chEndMostLeft = ' ';
                int minPos = i-1;
                for(map<char, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
                    if (it->second < minPos)
                    {
                        chEndMostLeft = it->first;
                        minPos = it->second;
                    }
                }
                mp.erase(chEndMostLeft);
                start = minPos + 1;
            }
            mp[ch] = i;
            ans = max(ans, i - start + 1);
        }
        return ans;
    }

    //extend: what if keep at most K distinct characters
    int lengthOfLongestSubstringKDistinct(string s, int K) { //O(n)
        map<char, int> mp; // ch -> count
        int ans = 0, start = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (mp.find(ch)!=mp.end())
                mp[ch]++;
            else {
                mp[ch] = 1;
                while (mp.size() > K) {
                    char startCh = s[start++];
                    int count = mp[startCh];
                    if (count > 1)
                        mp[startCh]--;
                    else
                        mp.erase(startCh);
                }
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};