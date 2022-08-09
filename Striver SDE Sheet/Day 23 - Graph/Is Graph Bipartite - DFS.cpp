class Solution {
private:
    bool dfs(vector<vector<int>>& adj, vector<int>& color, int node, int c) {
        color[node] = c;
        int newColor = 1-c;
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                if(dfs(adj, color, it, newColor) == false)  return false;
            }
            else if(color[it] == c) return false;
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n+1,-1);
        for(int i=0; i<n; ++i) {
            if(color[i] == -1) {
                if(dfs(adj, color, i, 0) == false) return false;
            }
        }
        return true;
    }
};