class Solution {
private : 
    bool detectCycle(int s, int &V, vector<int> adj[], vector<bool>& visited)     {
        
        // Create a queue for BFS 
        queue<pair<int,int>> q; // pair of vertex and its parent
        visited[s] = true; 
        q.push({s,-1});
        
        while(!q.empty()) {
            int vertex = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it : adj[vertex]) {
                if(!visited[it]) {
                    visited[it] = true;
                    q.push({it,vertex});
                }
                else if(parent != it) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V+1, 0);
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                bool ans = detectCycle(i,V,adj,visited);
                if(ans == true) return true;
            }
        }
        
        return false;
    }
};