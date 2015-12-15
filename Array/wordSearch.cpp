#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int n, m;
	bool** mask;

	bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
		if (n == 0) return word.compare("")==0;
		if (word.compare("")==0) return true;
		m = board[0].size();
		//cout<<"n,m="<<n<<","<<m<<" len="<<word.length()<<endl;
		if (n*m<word.length()) return false;

		//pre-pruning : character histogram
		vector<int> cnt(256,0), available(256,0);
		for (int i = word.length()-1; i>=0; i--)
		{
			cnt[word[i]-'A']++;
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				available[board[i][j]-'As']++;
		bool ans = true;
		for (int i = 0; i < 256; i++)
		{
			if (available[i]<cnt[i])
			{
				ans=false;
				break;
			}
		}
		if (ans==false) return false;

		//dfs
		mask = new bool*[n];
		for (int i = 0; i < n; i++)
		{
			mask[i] = new bool[m];
			for(int j = 0; j <m; j++)
				mask[i][j]=false;
		}

		ans = false;
		for (int i = 0; i < n && !ans; i++)
			for (int j = 0; j < m && !ans; j++)
			{
				if (board[i][j]==word[0])
				{
					mask[i][j]=true;
					if(search(board, word, 1, i, j))
					{
						//cout<<"start "<<i<<","<<j<<endl;
						ans = true;
						break;
					}
					mask[i][j]=false;
				}
			}
		return ans;
    }

	bool search(vector<vector<char>>& board, string word, int ith, int x, int y) {
		//cout<<x<<","<<y<<endl;
		static int dir[4][2] = {-1,0,0,1,1,0,0,-1};
		if (word.length() == ith)
		{
			return true;
		}
		
		for (int i = 0; i < 4; i++)
		{
			int xx = x+dir[i][0], yy = y + dir[i][1];
			//cout<<xx<<":"<<yy<<endl;
			if (xx>=0&&xx<n&&yy>=0&&yy<m&&word[ith]==board[xx][yy]&&!mask[xx][yy])
			{
				mask[xx][yy]=true;
				if(search(board, word, ith+1, xx, yy)) return true;
				mask[xx][yy]=false;
			}
		}

		return false;
	}

	static void test()
	{
		int n;
		string str,target;
		vector<vector<char>> board;
		cin>>n;
		for (int i = 0; i < n; i++)
		{
			cin>>str;
			board.push_back(vector<char>(str.length()));
			for (int j = 0; j < str.length(); j++)
				board[i][j]=str[j];
		}
		cin>>target;
		Solution sol;
		cout<<"result="<<sol.exist(board, target)<<endl;
	}
};