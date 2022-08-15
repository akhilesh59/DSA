/*
    Note: To check for negative weight cycle, do this at the end:

    bool flag = 0; 
    for(auto it: edges) {
        if(dist[it[0]] + it[2] < dist[it[1]]) {
            flag = 1; 
            break; 
        }
    }

    if(flag) -> Negative weight cycle exists.
*/

class Solution{
	public:
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
       vector<int>dist(V, 1e8);
       dist[S] = 0;
       
       for(int i = 0; i < V-1; i++){
           for(auto it : adj){
               if(dist[it[0]] + it[2] < dist[it[1]]){
                   dist[it[1]] = dist[it[0]] + it[2];
               }
           }
       }
       
       return dist;
   }
};