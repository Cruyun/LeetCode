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
    unordered_map<int,UndirectedGraphNode*> mp;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return NULL;
        }
        UndirectedGraphNode *one = NULL;
        if (mp.count(node->label)) {
            one = mp[node->label];
        } else {
            one = new UndirectedGraphNode(node->label);
            mp[node->label] = one;
        }
        
        int s = node->neighbors.size();
        for (int i = 0; i < s; i++) {
            if (mp.count(node->neighbors[i]->label)) {
                one->neighbors.push_back(mp[node->neighbors[i]->label]);
            } else {
                UndirectedGraphNode *two = new UndirectedGraphNode(node->neighbors[i]->label);
                mp[node->neighbors[i]->label] = two;
                one->neighbors.push_back(two);
                cloneGraph(node->neighbors[i]);
            }
        }
        return one;
    }
};