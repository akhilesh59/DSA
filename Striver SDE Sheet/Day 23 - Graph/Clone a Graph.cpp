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
        if(!node) return NULL;
        
        Node* clone = new Node(node->val);
        vector<Node*> vis(105, NULL); // It will contain the nodes of only the clone graph.
        
        vis[node->val] = clone;
        queue<Node*> q; // This queue will contain only the nodes of the given graph, because it will be used for traversal.
        q.push(node);
        
        while(!q.empty()) {
            Node* curr = q.front(); q.pop();
            for(auto it : curr->neighbors) {
                if(vis[it->val] == NULL) { // Not visited
                    Node* tmp = new Node(it->val);
                    vis[it->val] = tmp; // We have inserted a node
                    q.push(it);                    
                }
                
                vis[curr->val]->neighbors.push_back(vis[it->val]); // add the nodes in the adjacency list only from the vis because this only contains the nodes of the clone graph.
            }
        }
        return clone;
    }
};