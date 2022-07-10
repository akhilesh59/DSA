vector<int> Solution::repeatedNumber(const vector<int> &v) {
    int n = v.size();
    int x = 0;
    for(auto it : v) x ^= it;
    for(int i=1; i<=n; i++) x ^= i;
    
    
    int idx = x & ~(x-1); // Extract the Rightmost Set bit Position
    
    int n1=0,n2=0;
    
    for(auto it : v) {
        if(it&idx) n1 ^= it;
        else n2 ^= it;
    }
    
    for(int i=1; i<=n; i++) {
        if(i&idx) n1 ^= i;
        else n2 ^= i;
    }
    
    // We ned to make sure that which is the repeating and missing no. before returning:
    int cnt = 0;
    for(auto it : v) if(it==n1) ++cnt;
    
    if(cnt) return {n1,n2};
        
    return {n2,n1};
}
