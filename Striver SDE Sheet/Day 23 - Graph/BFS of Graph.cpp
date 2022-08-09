// Here only the connected component having node 0 is taken into consideration

class Solution {
private:

    void bfs(vector<int> adj[], vector<int>& ans, vector<int>& vis, int node) {
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            ans.push_back(curr);
            for(auto it : adj[curr]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans, vis(V+1,0);
        bfs(adj, ans, vis, 0);
        return ans;
    }
};