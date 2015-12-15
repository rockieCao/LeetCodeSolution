#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
// test case:
// [0,1,2,4,5,7]
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
		vector<string> res;
		if (n < 1) return res;
		stringstream sstream;

		int st = nums[0], ed = nums[0]+1;
		for (int i = 1; i < n; i++)
		{
			if (nums[i]==ed)
			{
				ed++;
			}
			else if(ed-st==1)
			{
				string tmp;
				sstream<<st;
				sstream>>tmp;
				res.push_back(tmp);
				sstream.clear();
				st = nums[i];
				ed = nums[i]+1;
			}
			else
			{
				string tmp;
				sstream<<st<<"->"<<ed-1;
				sstream>>tmp;
				res.push_back(tmp);
				sstream.clear();
				st = nums[i];
				ed = nums[i]+1;
			}
		}
		// note: don't forget to handle the last range
		if(ed-st==1)
		{
			string tmp;
			sstream<<st;
			sstream>>tmp;
			res.push_back(tmp);
			sstream.clear();
		}
		else if(ed-st>1)
		{
			string tmp;
			sstream<<st<<"->"<<ed-1;
			sstream>>tmp;
			res.push_back(tmp);
			sstream.clear();
		}


		return res;
    }

	static void test()
	{
		int n, x;
		vector<int> vec;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			vec.push_back(x);
		}
		Solution sol;
		cout<<"result:";
		vector<string> res = sol.summaryRanges(vec);
		for (string str : res)
		{
			cout<<str<<",";
		}
		cout<<endl;
	}
};
