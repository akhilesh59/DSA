class Solution
{
private:

    void dfs(vector<int> adj[], vector<int>& ans, int node, vector<int>& vis) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) dfs(adj, ans, it, vis);
        }
        ans.push_back(node);
    }

public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans, vis(V+1);
	    for(int i=0; i<V; ++i) {
	        if(!vis[i]) dfs(adj, ans, i, vis);
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};