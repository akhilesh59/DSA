class Solution {
private:

void dfs(int node, vector<int>& ans, vector<bool>& vis, vector<int> adj[]) {
    
    if(vis[node] == 0) {
        ans.push_back(node);
        vis[node] = 1;
        
        for(auto it : adj[node]) {
            if(vis[it] == 0) {
                dfs(it, ans, vis, adj);
            }
        }
    }
    
}

  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V+1,0);
        
        // stack<int> st;
        // st.push(0);
        // // vis[0] = 1;
        
        // while(!st.empty()) {
        //     int node = st.top();
        //     st.pop();
            
        //     if(vis[node] == 0) {
        //         dfs.push_back(node);
        //         vis[node] = 1;
        //     }
            
        //     for(auto it : adj[node]) {
        //         if(vis[it] == 0) {
        //             st.push(it);
        //             // vis[it] = 1;
        //         }
        //     }
        // }
        
        dfs(0, ans, vis, adj);
        
        return ans;
    }
};