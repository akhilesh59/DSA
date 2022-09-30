vector<int> Solution::solve(vector<int> &a, vector<int> &b, int k) {
    vector<int> ans;
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    // Will hold the {sum, {i,j}} :
    priority_queue<pair<int, pair<int,int>>> pq; 
    
    set<pair<int,int>> st; // will hold the set of indices of a sum
    
    int i=0,j=0;
    
    pq.push({a[i]+b[j], {i,j}});
    st.insert({i,j});
    
    while(k--) {
        auto it = pq.top(); pq.pop();
        
        int sum = it.first;
        ans.push_back(sum);
        int i = it.second.first;
        int j = it.second.second;
        
        if(st.find({i+1, j}) == st.end()) {
            pq.push({a[i+1]+b[j], {i+1, j}});
            st.insert({i+1, j});
        }
        if(st.find({i, j+1}) == st.end()) {
            pq.push({a[i]+b[j+1], {i, j+1}});
            st.insert({i, j+1});
        }
    }
    
    return ans;
}
