#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Topo sort
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indeg (numCourses, 0);
        vector<set<int>> g (numCourses, set<int>());
        vector<set<int>> rg (numCourses, set<int>());

        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i].first, v = prerequisites[i].second;
            if (g[u].find(v) == g[u].end())
                indeg[u]++;
            g[u].insert(v);
            rg[v].insert(u);
        }

        vector<int>que;
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i]==0)
                que.push_back(i);
        }
        int front = 0;
        while (front<que.size())
        {
            int cur = que[front];
            ++front;

            for (set<int>::iterator it = rg[cur].begin(); it != rg[cur].end(); it++) {
                indeg[*it]--;
                if (indeg[*it]==0)
                    que.push_back(*it);
            }
        }

        if (front == numCourses) return que;
        else return vector<int>();
    }
};