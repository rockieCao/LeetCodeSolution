#include<iostream>
#include<vector>
using namespace std;

/*Problem: Graph Valid Tree
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Solution: quick union
*/

class Solution {
public:
    vector<int> father;
    
    bool validTree(int n, vector<pair<int,int>>& edges) {
        int m=edges.size();
        if(m!=n-1) return false;
        
        father=vector<int>(n);
        for(int i=0;i<n;++i) father[i]=i;
        
        for(int i=0;i<m;++i) {
            int u=edges[i].first;
            int v=edges[i].second;
            if(u==v) return false;
            int ufa=findFa(u);
            int vfa=findFa(v);
            if(ufa==vfa) return false;
            unionSet(ufa,vfa);
        }
        
        /*for(int i=1;i<n;++i)
            if(findFa(i-1)!=findFa(i)) return false;*/ //no need since #edge==n-1
        
        return true;
    }
    
    int findFa(int u) {
        if(father[u]==u) return u;
        else return father[u]=findFa(father[u]);
    }
    
    void unionSet(int u, int v) {
        if(u!=v) {
            father[u]=v;
        }
    }
    
    static void test() {
        int n,m,u,v;
        Solution sol;
        vector<pair<int,int>> edge;
        while(cin>>n>>m) {
            for(int i=0;i<m;++i) {
                cin>>u>>v;
                edge.push_back(pair<int,int>(u,v));
            }
            cout<<"ans="<<sol.validTree(n, edge)<<endl;
        }
    }
};

