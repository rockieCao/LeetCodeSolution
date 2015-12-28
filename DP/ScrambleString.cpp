#include <iostream>
#include <string>
#include <vector>
using namespace std;
//s1[i..i+len]和s2[j..j+len]满足scramble string的充要条件是s1[i..i+k-1]==s2[j..j+k-1]&&s[i+k..i+len-1]==s2[j+k..j+len-1]||s1[i..i+k-1]==s2[j+len-k..j+len-1]&&s1[i+k..i+len-1]==s2[j..j+len-k-1]
//dp[i][j][len]表示以i和j为起点，长度为len的字符串是不是满足scramble string
//then dp[i][j][len]=(dp[i][j][k]&&dp[i+k][j+k][len-k])||(dp[i][j+l-k][k]&&dp[i+k][j][l-k]); 
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int slen = s1.length();
        int tlen = s2.length();
        if (slen!=tlen) return false;
        if (slen==0) return true;
        
        vector<vector<vector<bool> > >dp(slen,vector<vector<bool> >(slen,vector<bool>(slen+1,false)));
        //initialize
        for(int i=0;i<slen;i++) {
            for(int j=0;j<tlen;j++) {
                if(s1[i]==s2[j])
                    dp[i][j][1]=true;   
            }   
        }
        
        for(int l=2;l<=slen;++l) {
            for(int i=0;i+l<=slen;i++) {
                for(int j=0;j+l<=tlen;j++) {
                    for(int k=1;k<l;++k) {
                        if((dp[i][j][k]&&dp[i+k][j+k][l-k])||(dp[i][j+l-k][k]&&dp[i+k][j][l-k])) {//注意括号范围 
                            dp[i][j][l]=true;
                            break;  
                        }
                    }
                }   
            }   
        }
        return dp[0][0][slen];
    }
    
    bool isScramble2(string s1, string s2) { //more efficient
        int slen = s1.length();
        int tlen = s2.length();
        if (slen!=tlen) return false;
        if (s1==s2) return true;
        int cnt[26]={0};
        for(int i=0;i<slen;++i) {
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']--;   
        }
        for(int i=0;i<26;++i)
            if (cnt[i]!=0) return false;
        for(int i=1;i<slen;i++) {
            bool ret=isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i));
            if (ret) return true;
            ret = (isScramble(s1.substr(0,i),s2.substr(slen-i))&&isScramble(s1.substr(i),s2.substr(0,slen-i)));
            if (ret) return true;
        }
        return false;
    }
};
