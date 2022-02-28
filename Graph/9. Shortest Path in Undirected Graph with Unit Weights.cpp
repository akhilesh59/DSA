/*
Question : Given a undirected graph with edge weights as unity. Find the shortest path to all nodes from a given source node.
*/

// BFS is used for such problems.

void BFS(vector<int> adj[], int N, int src) {

    vector<int> dis(N,INT_MAX);

    queue<int> q;
    q.push(src);

    dis[src] = 0;

    while(!q.empty()) {
        int node = q.front(); q.pop();

        for(auto it : adj[node])  {
            if(dis[node]+1 < dis[it]) {
                dis[it] = dis[node]+1;
                q.push(it);
            }
        }
    }

    for(int i=0; i<N; i++) cout<<dis[i]<<' ';

}