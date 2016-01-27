#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    bool canFinish3(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            indeg[prerequisites[i].first]++;
        }
        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) que.push(i);
        }

        int count = que.size();
        while (!que.empty()) {
            int cur = que.front();
            que.pop();

            for (int i = 0; i < prerequisites.size(); i++) {
                if (cur == prerequisites[i].second) {
                    int pa = prerequisites[i].first;
                    indeg[pa]--;
                    if (indeg[pa]==0) {
                        que.push(pa);
                        ++count;
                    }
                }
            }
        }

        if (count == numCourses) return true;
        else return false;
    }

    bool canFinish4(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses <= 0) return true;

        vector<set<int>> g(numCourses, set<int>());
        vector<set<int>> rg(numCourses, set<int>());

        for (int i = prerequisites.size()-1; i >= 0; i--) {
            g[prerequisites[i].first].insert(prerequisites[i].second);
            rg[prerequisites[i].second].insert(prerequisites[i].first);
        }

        set<int> st;
        for (int i = 0; i < numCourses; i++)
            st.insert(i);
        
        vector<int> seq;
        while (!st.empty()) {
            bool change =false;
            seq.clear();
            for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
                if (g[*it].empty()) {
                    seq.push_back(*it);
                    change = true;
                    for (set<int>::iterator it2 = rg[*it].begin(); it2 != rg[*it].end(); it2++)
                    {
                        g[*it2].erase(*it);
                    }
                }
            }
            if (!change) break;
            for (vector<int>::iterator it = seq.begin(); it != seq.end(); it++) {
                st.erase(*it);
            }
        }

        return st.size() == 0;
    }

    bool canFinish2(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        vector<set<int>> g(numCourses, set<int>());
        vector<set<int>> rg(numCourses, set<int>());
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i].first, v = prerequisites[i].second;
            if (g[u].find(v) == g[u].end())
                indeg[u]++;
            g[u].insert(v);
            rg[v].insert(u);
        }
        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) que.push(i);
        }

        int count = que.size();
        while (!que.empty()) {
            int cur = que.front();
            que.pop();

            for(set<int>::iterator it=rg[cur].begin(); it != rg[cur].end(); it++) {
                indeg[*it]--;
                if (indeg[*it]==0) {
                    que.push(*it);
                    ++count;
                }
            }
        }

        if (count == numCourses) return true;
        else return false;
    }

    bool hasCycle;
    vector<bool> mark, track;
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) { //DFS
        vector<set<int>> g(numCourses, set<int>());
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i].first, v = prerequisites[i].second;
            g[u].insert(v);
        }
        mark = vector<bool>(numCourses,false);
        track = vector<bool>(numCourses,false);
        hasCycle = false;
        for (int i = 0; i < numCourses; i++)
        {
            if (!mark[i]) visit(g, i);
            if (hasCycle) break;
        }

        return !hasCycle;
    }

    void visit(vector<set<int>>& g, int cur) {
        mark[cur] = true;
        track[cur] = true;
        for(set<int>::iterator it = g[cur].begin(); it != g[cur].end(); it++) {
            if (track[*it]) hasCycle = true;
            else visit(g, *it);
            if (hasCycle) return;
        }
        track[cur] = false; //note here to clean flag after each traverse
    }

    static void test() {
        int n, m, u, v;
        cin>>n>>m;
        vector<pair<int,int>> edge(m,pair<int,int>());
        for (int i = 0; i < m; i++)
        {
            cin>>u>>v;
            edge[i].first = u;
            edge[i].second = v;
        }
        cout<<"result="<<(Solution().canFinish(n, edge)?0:1)<<endl;
    }
};
