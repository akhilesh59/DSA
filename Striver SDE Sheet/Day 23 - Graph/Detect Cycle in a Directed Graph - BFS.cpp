class Solution {
private: 
    bool detectCycleBFS(vector<vector<int>>& preq, int numCourses) {
        vector<int> adj[numCourses+1];
        vector<int> indegree(numCourses,0);
        int n = preq.size();
        for(int i=0; i<n; ++i) {
            int u = preq[i][0], v = preq[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0; // will contain the count of nodes encountered in Topo sort
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
            
        }
        return (count == numCourses);
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        bool ans = detectCycleBFS(preq, numCourses);
        
        return ans;
    }
};