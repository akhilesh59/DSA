class Solution
{
    
    /* Note: We might have used the answer vector instead of stack, and the only change we 
    should have done is to pass the ans vector and push back the node in the vector instead
    of the stack. And at last, just reverse the vector and return it*/
    
private:

    void topo_dfs(vector<int> adj[], vector<bool>& vis, stack<int>& st, int node) {
        
        vis[node] = 1;
        
        for(auto it : adj[node]) {
            if(!vis[it]) topo_dfs(adj, vis, st, it);
        }
        
        st.push(node);
        
    }

public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> vis(V);
	    vector<int> ans;
	    stack<int> st;
	    
	    for(int i=0; i<V; i++) {
	        if(!vis[i]) topo_dfs(adj, vis, st, i);
	    }
	    
	    while(!st.empty()) {
	        ans.push_back(st.top());
	        st.pop();
	    }
	   
	   //reverse(ans.begin(), ans.end());
	    
	    return ans;
	}
};