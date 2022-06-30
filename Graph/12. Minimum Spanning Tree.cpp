class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans = 0;
        
        vector<int> parent(V, -1);
        vector<int> cost(V, INT_MAX);
        vector<int> vis(V, 0);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        parent[0] = -1;
        cost[0] = 0;
        pq.push({0,0});
        
        while(!pq.empty()) {
            auto i = pq.top(); 
            pq.pop();
            int curr = i.second;
            
            vis[curr] = 1;
            
            for(auto it : adj[curr]) {
                int node = it[0];
                int wt = it[1];
                if(vis[node] == 0 && cost[node] > wt) {
                    parent[node] = curr;
                    cost[node] = wt;
                    pq.push({cost[node], node});
                }
            }
        }
        
        for(int i=0; i<V; i++) ans += cost[i];
        
        return ans;
        
    }
};