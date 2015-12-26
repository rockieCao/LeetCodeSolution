#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*解法一：类似剥洋葱的方法，就是一层一层的褪去叶节点，最后剩下的一个或两个节点就是我们要求的最小高度树的根节点*/
/*解法二(todo)：所求根节点一定在最长路径上，两边DFS或BFS在O(N)时间可以找到最长路径，如果len为偶数，则输出中间两个节点；否则输出中间一个节点即可*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> deg(n,0);
        vector<vector<int>> g(n,vector<int>());
        for(int i=0;i<edges.size(); i++) {
            int u=edges[i].first,v=edges[i].second;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        
        queue<int> que;
        for(int i=0;i<n;++i) {
            if(deg[i]==1) que.push(i);    
        }
        
        while(n>2) {
            int sz=que.size();
            for(int i=0;i<sz;++i) {
                int u=que.front();
                que.pop();
                --n;
                for(int v:g[u]) {
                    --deg[v];
                    if(deg[v]==1) que.push(v);    
                }
            }
        }
        
        vector<int> res;
        while(!que.empty()) {
            res.push_back(que.front());
            que.pop();    
        }
        return res;
    }
};
