vector<int> parent(1e5+5), rank(1e5+5, 0);

void makeSet(int n) {
    for(int i=1; i<=n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find_parent(int node) {
    if(node == parent[node]) return node;

    return parent[node] = find_parent(parent[node]); // Rank Compression
}

void Union(int u, int v) {
    u = find_parent(u);
    v = find_parent(v);

    if(rank[u] > rank[v]) {
        parent[v] = u;
    }
    else if(rank[v] > rank[u]) {
        parent[u] = v;
    }
    else {
        parent[u] = v;
        rank[u]++;
    }
}


int main() {
    int n; cin >> n; // n will be the number of nodes
    makeSet();

    return 0;
}