#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//test cases
//[0, 1, 3, 50, 75], lower=0, upper=99 return ["2", "4->49", "51->74", "76->99"]
//[0, 1, 3, 50, 75], lower=100,upper=101 return ["100->101"]
//[0, 1, 3, 50, 75], lower=2, upper=74 return ["2", "4->49", "51->74"]
//[0, 1, 3, 50, 75], lower=5, upper=75 return ["5->49", "51->74"]
class Solution
{
public:
	vector<string> findMissingRanges(vector<int> nums, int lower, int upper) {
		vector<string> res;
		stringstream sstream;
		int cur = lower, n = nums.size(), pre = lower-1;
		for (int i = 0; i <= n; i++)
		{
			if (i<n&&nums[i]<lower) 
			{
				continue;
			}
			if (i == n)
				cur = upper+1;
			else
				cur = nums[i];
			if (cur-pre==2)
			{
				sstream<<cur-1;
				string tmp;
				sstream>>tmp;
				res.push_back(tmp);
				sstream.clear();
			}
			else if (cur-pre>2)
			{
				string tmp;
				sstream<<pre+1<<"->"<<cur-1;
				sstream>>tmp;
				res.push_back(tmp);
				sstream.clear();
			}
			pre = cur;
		}
		return res;
	}

	static void test()
	{
		int n, x, lower, upper;
		vector<int> nums;

		cin>>n>>lower>>upper;
		for (int i = 0; i < n; i++)
		{
			cin>>x;
			nums.push_back(x);
		}
		Solution sol;
		cout<<"Result:";
		vector<string> res=sol.findMissingRanges(nums, lower, upper);
		for(string elem : res)
			cout<<elem<<",";
		cout<<endl;
	}
};
