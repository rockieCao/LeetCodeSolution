#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Similar thinking as LongestSubstrWithoutRepeat and SubstringConcateAllWords
// 2 pointers: tailPtr continue to increase; headPtr try to chase tailPtr when satisfy some condition
class Solution {
public:
    string minWindow(string S, string T) {
        int sLen = S.length(), tLen = T.length();
        if (sLen == 0 || tLen == 0 || sLen < tLen) return "";
        int maxCount[256];
        memset(maxCount, 0, 256*sizeof(int));
        int totalCount = 0;
        for (int i = 0; i < tLen; i++)
        {
            if (maxCount[T[i]]==0) ++totalCount;
            maxCount[T[i]]++;
        }

        int start = 0, end  = 0, minLen = sLen+1, bestStart = 0, count = 0;
        int curCount[256];
        memset(curCount, 0, 256*sizeof(int));
        while (end < sLen)
        {
             if (maxCount[S[end]]>0)
            {
                curCount[S[end]]++;
                if (curCount[S[end]]==maxCount[S[end]])
                    count++;
                while (count==totalCount && start<=end)
                {
                    if (count == totalCount)
                    {
                        if(end-start+1<minLen)
                        {
                            minLen = end-start+1;
                            bestStart = start;
                        }
                    }
                    if (maxCount[S[start]]>0)
                    {
                        if (curCount[S[start]] == maxCount[S[start]])
                            count--;
                        curCount[S[start]]--;
                    }
                    ++start;
                }
            }
            ++end;
        }

        if (minLen > sLen) return "";
        else return S.substr(bestStart, minLen);
    }

    static void test() {
        string S, T;
        cin>>S>>T;
        Solution sol;
        cout<<"result="<<sol.minWindow(S,T)<<endl;
    }
};