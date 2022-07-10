int Solution::solve(vector<int> &v, int t) {
    int cnt = 0, n = v.size();
    int prefixXor = 0;
    unordered_map<int,int> mp;
    
    for(int i=0; i<n; i++) {
        prefixXor ^= v[i];
        int rem_val = prefixXor ^ t;
        if(prefixXor == t) {
            cnt++;
        }
        if(mp.find(rem_val) != mp.end()) {
            cnt = cnt + mp[rem_val];
        }
        mp[prefixXor]++;
    }
    
    return cnt;
    
}
