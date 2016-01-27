#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    struct UndirectedGraphNode {
        int label;
        vector<UndirectedGraphNode *> neighbors;
        UndirectedGraphNode(int x): label(x) {};
    };

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return node;

        unordered_map<int, UndirectedGraphNode*> mp;
        return cloneG(node, mp);
    }

    UndirectedGraphNode *cloneG(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*> &mp) {
        if (node == NULL) return NULL;
        if (mp.find(node->label)!=mp.end()) return mp[node->label];

        UndirectedGraphNode *newNd = new UndirectedGraphNode(node->label);
        newNd->neighbors = vector<UndirectedGraphNode*>((node->neighbors).size());
        mp[node->label] = newNd;
        for (int i = 0; i < (node->neighbors).size(); i++)
        {
            (newNd->neighbors)[i] = cloneG((node->neighbors)[i], mp);
        }

        return newNd;
    }
};
