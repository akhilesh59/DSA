#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m,src;
    cin >> n >> m >> src;

    vector<pair<int,int>> adj[n+1];

    int u,v,wt;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    cin >> src;

    /* Dijkstra's Algorithm */
     
    priority_queue<pair<int,int>>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // Min heap, stores pair of (dist, upto)

    vector<int> dist(n+1, INT_MAX);
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for(auto it : adj[curr]) {
            int next = it.first;
            int next_d = it.second;

            if(dist[next] > dist[curr] + next_d) {
                dist[next] = dist[curr] + next_d;
                pq.push({dist[next], next});
            }
        }

        cout<< " The distances from the source, " << src << " , are : \n";
        for(int i=1; i<=n; i++) cout<<dist[i]<<' ';
        cout<<'\n';

        return 0;
    }

    return 0;
}