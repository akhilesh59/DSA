class Solution {
private:

    void dfs(vector<int> adj[], int node, vector<int>& vis, vector<int>& ans) {
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto it : adj[node]) {
            if(!vis[it]) dfs(adj, it, vis, ans);
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans, vis(V,0);
        for(int i=0; i<V; ++i) {
            if(!vis[i]) dfs(adj, i, vis, ans);
        }
        return ans;
    }
};