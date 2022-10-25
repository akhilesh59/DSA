class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Prims Algorithm:
        vector<int> par(V+1, -1);
        vector<int> cost(V+1, INT_MAX);
        vector<int> vis(V+1, 0);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,0}); // {cost, node}
        par[0] = -1;
        cost[0] = 0;
        
        while(!pq.empty()) {
            int curr = pq.top().second;
            pq.pop();
            
            vis[curr] = 1;
            
            for(auto it : adj[curr]) {
                int node = it[0];
                int wt = it[1];
                
                if(!vis[node] && wt < cost[node]) {
                    cost[node] = wt;
                    par[node] = curr;
                    pq.push({wt, node});
                    
                }
            }
            
        }
        
        int mst_cost = 0;
        for(int i=0; i<V; ++i) {
            mst_cost += cost[i];
        }
        
        return mst_cost;
    }
};
