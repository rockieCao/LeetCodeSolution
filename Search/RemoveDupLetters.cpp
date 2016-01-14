#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

/*Problem:
remove duplicate letters so that every letter appear once and only once. make sure the result is the smallest in lexicographical order among all possible results.

Solution:
For example, "cbacdcbc"
1.find out the last appeared position for each letter; c - 7 b - 6 a - 2 d - 4 //->this letter must appears before or at the last position
2.find out the smallest index from the map in step 1 (a - 2); //->if there's a letter smaller than current "must appear element", it should output first; then comes the second smallest one; ... until current "must appear element" is the smallest in current range [begin,end]
3.the first letter in the final result must be the smallest letter from index 0 to index 2;
4.repeat step 2 to 3 to find out remaining letters.
 ?the smallest letter from index 0 to index 2: a
 ?the smallest letter from index 3 to index 4: c
 ?the smallest letter from index 4 to index 4: d
 ?the smallest letter from index 5 to index 6: b

so the result is "acdb"

*/

class Solution {
public:
    
    string removeDuplicateLetters(string s) {
        int n=s.length();
        if(n<=1) return s;
        vector<int> mp(26,-1);
        for(int i=0;i<n;++i) {
            mp[s[i]-'a']=i;
        }
        string res="";
        int begin=0,end=findMinLastPos(mp);
        for(int i=0;i<n;++i) {
            char minChar='z'+1;
            int minCharPos = end;
            for(int j=begin;j<=end;++j) {
                if(mp[s[j]-'a']!=-1&&minChar>s[j]) {
                    minChar=s[j];
                    minCharPos=j;
                }
            }
            res+=minChar;
            if(i==n-1) break;
            
            mp[minChar-'a']=-1;
            begin=minCharPos+1;
            if(minChar==s[end]) {
                end=findMinLastPos(mp);    
                if(end==-1) break;
            }
        }
        
        return res;
    }
    
    int findMinLastPos(vector<int> &mp) {
        int ret=INT_MAX;
        for(int i=0;i<26;++i) {
            if(mp[i]!=-1&&ret>mp[i]) ret=mp[i];
        }
        return ret==INT_MAX?-1:ret;
    }
    
    string removeDuplicateLetters2(string s) { //use a virtual stack
        vector<int> cnts(256, 0);
        for (char c : s) {
            ++cnts[c];
        }

        vector<bool> isVisited(256, false);     
        string results;
        for (char c : s) {
            --cnts[c];

            if (isVisited[c] // this char appearred earlier
                || (!results.empty() && (results.back() == c))) { // this char already exists in results
                continue;
            }
            while (!results.empty() && (results.back() > c) && (cnts[results.back()] > 0)) { // a better option found
                // rewithdraw the previous decision
                isVisited[results.back()] = false;
                results.pop_back();
            }
            // set up this new record
            results.push_back(c);
            isVisited[c] = true;
        }

        return results;
    }
    
    static void test() {
        string str;
        Solution sol;
        while(cin>>str) {
            cout<<"ans="<<sol.removeDuplicateLetters(str)<<endl;
        }
    }
};

