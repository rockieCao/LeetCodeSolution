#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*Problem: Strobogrammatic Number II
Description:
    A strobogrammatic number is a number that looks the same when rotated 180 degrees 
    (looked at upside down).
    Find all strobogrammatic numbers that are of length = n. 
    For example,
    Given n = 2, return ["11","69","88","96"].
*/
class Solution {
public:
    unordered_map<char, char> d;
    vector<char> single;
    
    Solution(){
        d.insert(pair<char, char>('0','0'));
        d.insert(pair<char, char>('1','1'));
        d.insert(pair<char, char>('6','9'));
        d.insert(pair<char, char>('8','8'));
        d.insert(pair<char, char>('9','6'));
        
        single.push_back('0');
        single.push_back('1');
        single.push_back('8');
        single.push_back('6');
        single.push_back('9');
    }
    
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        if (n==0) return res;
        if (n==1) {
            for(int i=0;i<single.size();++i)
                res.push_back(string(1,single[i]));
            return res;
        }
        string tmp="";
        search(0, n/2-1, tmp, res);
        for(int i=0;i<res.size();++i) {
            for(int j=n/2-1;j>=0;--j)
                res[i].append(1,d[res[i][j]]);   
        }
        if (n%2==1) {
            vector<string> res2;
            for(int i=0;i<res.size();++i) {
                for(int j=0; j<3; ++j) {
                    string tmp=res[i];
                    tmp.insert(n/2,1,single[j]);
                    res2.push_back(tmp);
                }
            }
            return res2;   
        }
        else
            return res;
    }
    
    void search(int s, int e, string cur, vector<string>& res) {
        if(s>e) {
            res.push_back(cur);
            return;  
        }
        for(int i=0; i<5; ++i) {
            if(s==0&&i==0) continue;
            search(s+1, e, cur+single[i], res);
        }
    }
    
    static void test() {
        Solution sol;
        int n;
        while(cin>>n) {
            vector<string> res=sol.findStrobogrammatic(n);
            for(string str:res) {
                cout<<str<<",";   
            }   
            cout<<endl;
        }   
    }
};
