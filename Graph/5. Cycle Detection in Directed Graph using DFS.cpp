// ---------------------------> DFS <--------------------------

class Solution {
private:
    
    bool chkCycle(vector<int> adj[], vector<bool>& vis, vector<bool>& dfs_vis, int node) {
        
        vis[node] = 1, dfs_vis[node] = 1;
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(chkCycle(adj, vis, dfs_vis, it)) return true;
            }
            else if(dfs_vis[it]) return true;
        }
        
        dfs_vis[node] = 0;
        return false;
        
    }
    
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool> vis(V,0), dfs_vis(V,0);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) if(chkCycle(adj, vis, dfs_vis, i)) return true;
        }
        return false;
        
    }
};


