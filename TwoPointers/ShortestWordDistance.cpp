#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*Problem: Shortest Word Distance
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

Solution: keep latest index of two words. O(n)
*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n=words.size(), idx1=-1,idx2=-1;
        int res=n;
        for(int i=0;i<n;++i) {
            if(words[i]==word1) {
                idx1=i;
                if(idx2!=-1) res=min(res,idx1-idx2);
            }
            else if(words[i]==word2) {
                idx2=i;
                if(idx1!=-1) res=min(res,idx2-idx1);   
            }
        }
        return (res==n)?-1:res;
    }
    
    static void test() {
        int n;
        Solution sol;
        cin>>n;
        vector<string> vec;
        string word1,word2;
        for(int i=0;i<n;++i) {
            cin>>word1;
            vec.push_back(word1);   
        }
        while(cin>>word1>>word2) {
            cout<<"ans="<<sol.shortestDistance(vec, word1, word2)<<endl;
        }
    }
};

