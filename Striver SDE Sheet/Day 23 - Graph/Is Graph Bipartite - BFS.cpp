class Solution {
private:
    bool bfs(vector<vector<int>>& adj, vector<int>& color, int node) {
        queue<int> q;
        q.push(node);
        color[node] = 0;
        
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            int col = color[curr];
            
            for(auto it : adj[curr]) {
                if(color[it] == -1) {
                    color[it] = 1-col;
                    q.push(it);
                }
                else {
                    if(color[it] == col) return false;
                }
            }            
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n+1,-1);
        for(int i=0; i<n; ++i) {
            if(color[i] == -1) {
                if(bfs(adj, color, i) == false) return false;
            }
        }
        return true;
    }
};