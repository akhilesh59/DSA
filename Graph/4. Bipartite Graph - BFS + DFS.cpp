class Solution {
private:
    
    bool bfs(vector<int> adj[], vector<int>& color, int curr) {
        queue<int> q;
	    q.push(curr);
	    color[curr] = 1;
	    
	    while(!q.empty()) {
	        int node = q.front(); q.pop();
	        for(auto it : adj[node]) {
	            if(color[it] == -1) {
	                color[it] = 1-color[node];
	                q.push(it);
	            }
	            else if(color[it] == color[node]) return false;
	        }
	    }
	    return true;
    }
    
    bool dfs(vector<int> adj[], vector<int>& color, int curr) {
        if(color[curr] == -1) color[curr] = 1;
        
        for(auto it : adj[curr]) {
	            if(color[it] == -1) {
	                color[it] = 1-color[curr];
	                if(!dfs(adj, color, it)) return false;
	            }
	            else if(color[it] == color[curr]) return false;
	        }
	        return true;
	    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V+1, -1);
	    
	    for(int i=0; i<V; i++) {
	        if(color[i] == -1) if(!dfs(adj, color, i)) return false;
	    }
	    
	    return true;
	}

};