using ll = long long;

class DisjointSet {
    vector<int> rank, size, par; // par is for parent;

public:
    DisjointSet(ll n) {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        par.resize(n+1);

        for(ll i=0; i<=n; ++i) {
            par[i] = i;
        }
    }

    int findPar(ll node) {
        if(node == par[node]) return node;
        
        return par[node] = findPar(par[node]);
    }

    void unionByRank(ll u, ll v) {
        ll pu = findPar(u);
        ll pv = findPar(v);

        if(pu == pv) return;

        if(rank[pu] < rank[pv]) {
            par[pu] = pv;
        }
        else if(rank[pu] > rank[pv]) {
            par[pv] = pu;
        }
        else {
            par[pv] = pu;
            rank[pu]++;
        }
    }

    void unionBySize(ll u, ll v) {
        ll pu = findPar(u);
        ll pv = findPar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            par[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            par[pv] = pu;
            size[pu] += size[pv];
        }
    }        
};

class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int,int>>> edges;
        
        for(int i=0; i<V; ++i) {
            int u = i;
            for(auto it : adj[u]) {
                int v = it[0];
                int wt = it[1];
                
                edges.push_back({wt, {u,v}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        int mst = 0;
        DisjointSet ds(V);
        
        for(auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findPar(u) != ds.findPar(v)) {
                mst += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return mst;
    }
};