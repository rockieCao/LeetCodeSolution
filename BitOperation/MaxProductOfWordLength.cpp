#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

/*Problem: Maximum Product of Word Length
Solution: use 26bits to represent each word and enumerate candidates to get max product. O(n^2)
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
		if (n<2) return 0;
		unordered_map<int,int> mp;
		unordered_map<int,int>::iterator it;
		vector<int> tlist;
		for(int i=0;i<n;++i) {
			int key=0;
			int len=words[i].length();
			for(int j=len-1;j>=0;--j) {
				key|=1<<(words[i][j]-'a');
			}
			it = mp.find(key);
			if(it==mp.end()) {
				mp[key]=len;
				tlist.push_back(key);
			}
			else if (it->second<len)
				mp[key]=len;
			
		}

		n=tlist.size();
		int ans=0;
		for(int i=0;i<n;++i) {
			int key1=tlist[i];
			for(int j=i+1;j<n;++j) {
				int key2=tlist[j];
				if((key1&key2)==0) {
					int tmp=mp[key1]*mp[key2];
					if(tmp>ans) ans=tmp;
				}
			}
		}
		return ans;
    }
};
