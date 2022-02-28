class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> indegree(V,0);
        queue<int> q;
        
        for(int i=0; i<V; i++) {
            for(auto it : adj[i]) indegree[it]++;
        }
        
        for(int i=0; i<V; i++) if(indegree[i] == 0) q.push(i);
        
        int cnt = 0;
        
        while(!q.empty()) {
            int node = q.front(); q.pop();
            cnt++;
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return (cnt == V) ? false : true;
        
        /*that is - if the nodes sorted in topo sort is equal to the total number of nodes then no cycle exists*/
        
    }
};