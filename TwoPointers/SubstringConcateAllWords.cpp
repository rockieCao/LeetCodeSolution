#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

/*
Problem:
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters. 

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"] 

You should return the indices: [0,9].

Solution:
Brute force can solve this problem.
A better solution:
 主要思想是一样的，最主要的就是会如何分段例如：
 三个字母一段 abc def ghi jk那么可以在分a bcd efg hij k还可以分ab cde fgh ijk然后再分就重复了。
 所以三个字母分为一段的只有三种分法，同样道理K个字母的只有K种分法。

optimization:
 当检测到有一个单词不相等的时候，如果后面的主串的字母数剩下小于lLen*len（L中的单词数和每个单词的字母数的乘积），那么就不用继续比较了
*/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int sLen = S.length();
        int lSize = L.size();
        vector<int> ans;
        if (sLen == 0 || lSize == 0)
            return ans;

        int cLen = L[0].length(), idSize = 0;
        map<string, int> idMap;
        map<string, int>::iterator it;
        vector<int> maxCount(lSize,0);
        
        for (int i = 0; i < lSize; i++)
        {
            if (idMap.find(L[i]) == idMap.end())
            {
                maxCount[idSize] = 1;
                idMap[L[i]] = idSize++;
            }
            else
                maxCount[idMap[L[i]]]++;
        }

        int start = 0, curSize = 0;
        for (int i = 0; i < cLen; i++)
        {
            start = i;
            curSize = 0;
            vector<int> matches(idSize,0);
            for (int j = i; j < sLen && (sLen-j)/cLen>=lSize-curSize; j+=cLen) // optimization
            {
                string sub = S.substr(j, cLen);
                it = idMap.find(sub);

                if (it==idMap.end())
                {
                    start = j+cLen;
                    curSize = 0;
                    matches.clear();
                    matches.resize(idSize,0);
                }
                else 
                {
                    if (matches[it->second] >= maxCount[it->second]) //move front pointer
                    {
                        while (start <= j)
                        {
                            string sub2 = S.substr(start, cLen);
                            start += cLen;
                            map<string,int>::iterator it2 = idMap.find(sub2);
                            if (it2!=idMap.end()) 
                            {
                                curSize--;
                                matches[it2->second]--;
                                if (it->second == it2->second) break;
                            }
                        }
                    }
                    // don't forget to add counter here
                    matches[it->second]++;
                    curSize++;
                    if (curSize == lSize)
                    {
                        ans.push_back(start);
                    }
                }
            }
        }
        return ans;
    }

    static void test() {
        int n;
        cin>>n;
        string S, temp;
        cin>>S;
        vector<string> L(n, "");
        for (int i = 0; i < n; i++) {
            cin>>L[i];
        }
        Solution sol;
        vector<int> res = sol.findSubstring(S, L);
        for (int i = 0; i < res.size(); i++) {
            cout<<res[i]<<",";
        }
        cout<<endl;

    }
};