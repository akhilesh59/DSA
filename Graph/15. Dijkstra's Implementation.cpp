/*
    Note: The adj list if of type vector<vector<int>> adj[] and it stores nodes connected to a 
    given node u in form -> u : {{v1,dis1}, {v2,dis2}, {v3,dis3}}
*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        int n = V, s = S;
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        pq.push({0,s});
        dis[s] = 0;
        
        while(!pq.empty()) {
            auto x = pq.top(); pq.pop();
            int node = x.second;
            int curr_dis = x.first;
            
            for(auto it : adj[node]) {
                int next_node = it[0];
                int next_node_dis = it[1];
                
                if(dis[next_node] > curr_dis + next_node_dis) {
                    dis[next_node] = curr_dis + next_node_dis;
                    pq.push({dis[next_node], next_node});
                }
            }
        }
        
        return dis;
    }
};