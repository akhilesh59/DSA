#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int m,n; cin >> m >> n;
    vector<int> pos(n);
    for(auto &i : pos) cin >> i;
    
    vector<int> rev(n);
    for(auto &i : rev) cin >> i;
    
    int t; cin >> t;
    
    /* n^2 wali approach:
    
    int dp[n+1] = {0};
    dp[0] = rev[0];
    
    int ans = 0;
    
    for(int i=1; i<n; i++) {
        int maxi = 0;
        
        for(int j=0; j<i; j++) {
            int dis = pos[i]-pos[j];
            
            if(dis > t) {
                maxi = max(maxi, dp[j]);
            }
        }
        
        dp[i] = maxi + rev[i];
        ans = max(dp[i],ans);
    }
    */
    
    // Order of Length of Highway wali approach:
    
    int dp[m+1]={0};
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++) {
        mp[pos[i]] = rev[i];
    }

    dp[0] = 0;
    
    for(int i=1; i<=m; i++) {
       if(mp.find(i) == mp.end()) dp[i] = dp[i-1];
       else{
           int include = mp[i];
           if(i-t-1 >=0) include += dp[i-t-1];
           int exclude = dp[i-1];
            dp[i] = max(include, exclude);
       }
       
    }
    
    cout<<dp[m]<<"\n";
    
    return 0;
}