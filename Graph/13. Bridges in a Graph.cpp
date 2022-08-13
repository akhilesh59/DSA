class Solution
{
private:

    vector<int> dis, low, vis;
    set<pair<int,int>> st;
    
    void dfs(vector<int> adj[], int node, int par, int& timer) {
        vis[node] = 1;
        dis[node] = low[node] = timer++;
        
        for(auto it : adj[node]) {
            if(it == par) continue;
            if(!vis[it]) {
                dfs(adj, it, node, timer);
                low[node] = min(low[node], low[it]);
            }
            else {
                low[node] = min(low[node], dis[it]);
            }
            
            if(low[it] > dis[node]) st.insert({node,it});
        }
    }

public:
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int n = V;
        dis.resize(n,-1);
        low.resize(n,-1);
        vis.resize(n, 0);
        
        int timer = 0;
        
        for(int i=0; i<n; ++i) {
            if(!vis[i]) dfs(adj, i, -1, timer);
        }
        
        if(st.count({c,d}) || st.count({d,c})) return 1;
        return 0;
        
    }
};
