class Solution
{
public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        int ans = 0;
        
        // Step 1: Find the Topological Sort
        vector<int> vis(V+1,0);
        stack<int> st;
        
        for(int i=0; i<V; ++i) {
            if(!vis[i]) dfsTopoSort(adj, vis, i, st);
        }
        
        // Step 2: Transpose the Graph
        vector<int> transpose[V+1];
        for(int i=0; i<V; ++i) {
            vis[i] = 0; // We are unmarking it, because it has already been marked by the dfsTopoSort
            for(auto it : adj[i]) transpose[it].push_back(i);
        }
        
        while(!st.empty()) {
            int node = st.top(); st.pop();
            if(!vis[node]) {
                ++ans;
                revDFS(transpose, vis, node);
            }
        }
        
        return ans;
    }

private:

    void dfsTopoSort(vector<int> adj[], vector<int>& vis, int node, stack<int>& st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) dfsTopoSort(adj, vis, it, st);
        }
        st.push(node);
    }
    
    void revDFS(vector<int> transpose[], vector<int>& vis, int node) {
        vis[node] = 1;
        for(auto it : transpose[node]) {
            if(!vis[it]) revDFS(transpose, vis, it);
        }
    }

};