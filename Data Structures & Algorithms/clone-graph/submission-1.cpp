/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return node;
        unordered_map<Node*, vector<Node*>> mp;
        vector<bool> visit(101, false);
        trav(node,visit,mp);
        unordered_map<Node*, Node*> cloneMap;
        for (auto it : mp) {
            Node* original = it.first;
            cloneMap[original] = new Node(original->val);
        }
        for (auto it : mp) {
            Node* original = it.first;
            vector<Node*> neighbors = it.second;

            for (auto it : neighbors) {
                cloneMap[original]->neighbors.push_back(cloneMap[it]);
            }
        }
        return cloneMap[node];
    }
    void trav(Node* node,vector<bool>& visit,unordered_map<Node*,vector<Node*>>& mp){
        if(node==NULL)
            return;
        if(visit[node->val]==true)
            return;
        visit[node->val]=true;
        mp[node] = node->neighbors;
        for(auto i:node->neighbors){
            trav(i,visit,mp);
        }
    }
};
