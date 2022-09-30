#include <bits/stdc++.h> 
class Heap {
    public:
    int v[10000] = {-1,0};
    int size = 0;

    void insert(int x) {
        ++size;
        int idx = size;
        v[idx] = x;

        while(idx > 1) {
            int parent = idx/2;

            if(v[parent] > v[idx]) {
                swap(v[parent], v[idx]);
                idx = parent;
            }
            else return;
        }
    }

    int del() {
        
        if(size == 0) return -1;
        
        int ans = v[1];
        v[1] = v[size];
        --size;

        int i=1;
        while(i <= size) {
            int left = 2*i;
            int right = 2*i+1;

            if(left <= size && v[i] > v[left]) {
                swap(v[i], v[left]);
                i = left;
            }
            else if(right <= size && v[i] > v[right]) {
                swap(v[i], v[right]);
                i = right;
            }
            else break;
        }

        return ans;
    }
};

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> res;
    Heap *heap = new Heap();
    for(auto it : q) {
        if(it[0] == 0) heap->insert(it[1]);
        else res.push_back(heap->del());
    }
    
    return res;
}
