#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*Problem: Shortest Word Distance II
This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

Solution: two-pointers traverse two lists
*/

class WordDistance {
private:
    unordered_map<string,vector<int>> wordidx;
public:
    WordDistance(vector<string>& words) {
        for(int i=0;i<words.size();++i) {
            if(wordidx.find(words[i])==wordidx.end())
                wordidx[words[i]]=vector<int>();
            wordidx[words[i]].push_back(i);
        }
    }
    
    //word1!=word2
    int shortest(string word1, string word2) {
        vector<int>& idx1 = wordidx[word1];
        vector<int>& idx2 = wordidx[word2];
        int cnt1=idx1.size(), cnt2=idx2.size();
        int res=INT_MAX, i1=0,i2=0;
        while(i1<cnt1&&i2<cnt2) { // two-pointers pursuit each other
            res=min(res,abs(idx1[i1]-idx2[i2]));
            if (idx1[i1]>idx2[i2]) ++i2;
            else ++i1;
        }
        return res;
    }
};

class Solution {
public:
    static void test() {
        int n;
        cin>>n;
        vector<string> vec;
        string word1,word2;
        for(int i=0;i<n;++i) {
            cin>>word1;
            vec.push_back(word1);   
        }
        WordDistance wd(vec);
        while(cin>>word1>>word2) {
            cout<<"ans="<<wd.shortest(word1, word2)<<endl;
        }
    }
};

