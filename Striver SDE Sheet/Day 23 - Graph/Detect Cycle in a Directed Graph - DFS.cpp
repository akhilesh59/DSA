class Solution {
private:
    
    bool dfs(vector<int> adj[], int node, vector<int>& vis, vector<int>& dfsVis) {
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(adj, it, vis, dfsVis)) return true;
            }
            else if(dfsVis[it]) return true;
        }
        dfsVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        int V = numCourses;
        vector<int> adj[numCourses+1];
        int n = preq.size();
        for(int i=0; i<n; ++i) {
            int u = preq[i][0], v = preq[i][1];
            adj[v].push_back(u);
        }
        vector<int> vis(V+1,0);
        vector<int> dfsVis(V+1,0);
        
        for(int i=0; i<V; ++i) {
            if(!vis[i]) {
                if(dfs(adj, i, vis, dfsVis)) return false;
            }
        }
        
        return true;
        
        // Here in this question we have to return true if there is no cycle, and if there is cycle then return false.
        // That is why we are returning the opposite answer that we return in Cycle Detection in Directed Graph.
    }
};