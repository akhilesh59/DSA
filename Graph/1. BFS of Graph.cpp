class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> bfs;
        vector<int> vis(V+1,0);
        
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it : adj[node]) {
                if(vis[it] == 0) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
            
        }
        
        // for(int i=0; i<V; i++) {
        //     if(vis[i] == 0) {
        //         queue<int> q;
        //         q.push(i);
        //         vis[i] = 1;
                
        //         while(!q.empty()) {
        //             int node = q.front();
        //             q.pop();
        //             bfs.push_back(node);
                    
        //             for(auto it : adj[node]) {
        //                 if(vis[it] == 0) {
        //                     q.push(it);
        //                     vis[it] = 1;
        //                 }
        //             }
                    
        //         }
                
        //     }
        // }
        
        return bfs;
        
    }
};