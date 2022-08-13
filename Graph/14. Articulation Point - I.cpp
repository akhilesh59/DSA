class Solution {
private:
    vector<int> dis, low, mark, vis;
    
    void dfs(vector<int>adj[], int node, int par, int& timer) {
        vis[node] = 1;
        dis[node] = low[node] = timer++;
        
        int child = 0;
        
        for(auto it : adj[node]) {
            if(it == par) continue;
            if(!vis[it]) {
                dfs(adj, it, node, timer);
                low[node] = min(low[node], low[it]);
                
                if(low[it] >= dis[node] && par != -1) mark[node] = 1;
                
                ++child;
            }
            else {
                low[node] = min(low[node], dis[it]);
            }
        }
        
        if(par == -1 && child > 1) {
            mark[node] = 1;
        }
        
    }
    
    
public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int n = V;
        vector<int> ans;
        dis.resize(n);
        low.resize(n);
        mark.resize(n);
        vis.resize(n);
        
        for(int i=0; i<n; ++i) {
            dis[i] = low[i] = -1;
            vis[i] = 0;
        }
        int timer = 0;
        
        for(int i=0; i<n; ++i) {
            if(!vis[i]) {
                dfs(adj, i, -1, timer);
            }
        }
        
        for(int i=0; i<n; ++i) if(mark[i]) ans.push_back(i);
        if(ans.size() == 0) return {-1};
        return ans;
    }
};