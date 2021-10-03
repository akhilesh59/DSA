#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin >> n >> k;
    
    vector<vector<int>> v(n, vector<int>(k));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            cin >> v[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int>(k));
    int least = INT_MAX;
    int sleast = INT_MAX;
    
    for(int i=0; i<k; i++) {
        dp[0][i] = v[0][i];
        if(dp[0][i] <= least) {
            sleast = least;
            least = dp[0][i];
        }
        else if(dp[0][i] <= sleast) {
            sleast = dp[0][i];
        }
    }
    
    for(int i=1; i<n; i++) {
        int nleast = INT_MAX;
        int nsleast = INT_MAX;
        
        for(int j=0; j<k; j++) {
            if(dp[i-1][j] != least) {
                dp[i][j] = v[i][j] + least;
            }
            else {
                dp[i][j] = v[i][j] + sleast;
            }
            if(dp[i][j] <= nleast) {
                nsleast = nleast;
                nleast = dp[i][j];
            }
            else if(dp[i][j] <= nsleast) {
                nsleast = dp[i][j];
            }
        }
        
        least = nleast;
        sleast = nsleast;
        
        // cout<<least<<" "<<sleast<<"\n";
    }
    
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<k; j++) {
    //         cout<< dp[i][j] <<" ";
    //     }
    //     cout<<"\n";
    // }
    
    int ans = INT_MAX;
    
    for(int i=0; i<k; i++) {
        ans = min(ans,dp[n-1][i]);
    }
    
    cout<<ans<<"\n";
    
    return 0;
}