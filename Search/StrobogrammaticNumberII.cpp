#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*Problem: Strobogrammatic Number II
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Find all strobogrammatic numbers that are of length = n.

For example, Given n = 2, return ["11","69","88","96"].

Solution: DFS to enumerate first half, then the second half is definite. If n is odd, enumerate digit at middle (can only be '0','1','8')
Special cases:
1. '0' cann't be first digit if the length is greater than 1;
*/

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        if(n==0) return res;
        
        int cmap[10];
        for(int i=0;i<10;++i) cmap[i]=-1;
        cmap[0]=0;
        cmap[1]=1;
        cmap[8]=8;
        cmap[6]=9;
        cmap[9]=6;
        
        int samemap[10];
        for(int i=0;i<10;++i) samemap[i]=-1;
        samemap[0]=0;
        samemap[1]=1;
        samemap[8]=8;
        
        if(n==1) {
            for(int i=0;i<10;++i)
                if(cmap[i]!=-1) res.push_back(to_string(i));
            return res;
        }
        
        vector<vector<int>> halfres;
        vector<int> tmp;
        search(0,n/2-1,cmap,tmp,halfres);
        for(int i=0;i<halfres.size();++i) {
            int left=0,right=n-1;
            string str(n,' ');
            while(left<right) {
                str[left]=char('0'+halfres[i][left]);
                str[right]=char('0'+cmap[halfres[i][left]]);
                ++left;
                --right;
            }
            if(n%2==1) {
                 for(int j=0;j<10;++j) {
                    if(samemap[j]!=-1) {
                        string str2(str);
                        str2[left]=char('0'+j);
                        res.push_back(str2);
                    }
                }
            }
            else {
                res.push_back(str);   
            }
        }
        
        return res;
    }
    
    void search(int ith, int n, int* cmap, vector<int> &tmp, vector<vector<int>> &halfres) {
        if(ith>n) {
            halfres.push_back(vector<int>(tmp.begin(), tmp.end()));
            return;
        }
        for(int i=0; i<10; ++i) {
            if(cmap[i]==-1) continue;
            if(i==0&&ith!=0) {
                tmp.push_back(0);
                search(ith+1,n,cmap,tmp,halfres);
                tmp.pop_back();
            }
            else if(i>0) { 
                tmp.push_back(i);
                search(ith+1,n,cmap,tmp,halfres);
                tmp.pop_back();
            }
        }
    }
    
    static void test() {
        int n;
        Solution sol;
        while(cin>>n) {
            vector<string> res=sol.findStrobogrammatic(n);
            cout<<"ans=[";
            for(int i=0;i<res.size();++i)
                cout<<res[i]<<",";
            cout<<"]"<<endl;
        }
    }
};
