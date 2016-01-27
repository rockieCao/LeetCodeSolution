#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

// similar as wordLadder but need to output all paths
// BFS(store parent node)+DFS(re-construct path)
// Note: iterator performs better than subscript

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > res;
        queue<string> que[2];
        que[0].push(start);
        dict.erase(start);
        dict.erase(end);
        bool ti = false;
        bool hit = false;
        set<string> st;
        unordered_map<string, vector<string>> path;
        while(!que[ti].empty())
        {
            while(!que[ti].empty())
            {
                string cur = que[ti].front();
                que[ti].pop();
                //next word
                for (int i = cur.length()-1; i>=0; i--)
                {
                    for (int j = 'a'; j <= 'z'; j++)
                    {
                        if (j==cur[i]) continue;
                        string tmp = cur;
                        tmp[i]=j;
                        if (tmp == end) // get result
                        {
                            hit = true;
                            path[tmp].push_back(cur);
                        }
                        else if (dict.count(tmp))
                        {
                            que[!ti].push(tmp);
                            path[tmp].push_back(cur);
                        }
                    }
                }
            }
            if (hit) break;
            ti = !ti;

            st.clear();
            while(!que[ti].empty()) {
                st.insert(que[ti].front());
                que[ti].pop();
            }

            for (string elem : st)
            {
                que[ti].push(elem);
                dict.erase(elem);
            }
        }

        if (!path.count(end)) return res;
        cout<<"here"<<endl;

        vector<string> curPath(1,end);
        dfs(res, curPath, path, start, end);
        return res;
    }

    void dfs(vector<vector<string>>& res, vector<string>& curPath, unordered_map<string, vector<string>>& candidates, string& start, string& cur)
    { //construct path
        if (cur == start)
        {
            res.push_back(curPath);
            reverse(res.back().begin(), res.back().end());
            return;
        }

        vector<string> v = candidates[cur];
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            curPath.push_back(v[i]);
            dfs(res, curPath, candidates, start, v[i]);
            curPath.pop_back();
        }
    }

    static void test()
    {
        int n;
        string beginWord, endWord;
        unordered_set<string> wordDict;
        cin>>beginWord>>endWord>>n;
        for(int i = 0; i < n; i++)
        {
            string x;
            cin>>x;
            wordDict.insert(x);
        }

        Solution sol;
        vector<vector<string>> res=sol.findLadders(beginWord, endWord, wordDict);
        for (vector<string> vec: res)
        {
            for (string elem : vec)
            {
                cout<<elem<<",";
            }
            cout<<endl;
        }
    }
};