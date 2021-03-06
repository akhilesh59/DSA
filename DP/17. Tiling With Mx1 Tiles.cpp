#include<iostream>
using namespace std;

int main() {
    int n,m; cin >> n >> m;
    
    int dp[n+1] = {0};
    dp[0] = 1;
    
    for(int i=1; i<=n; i++) {
        if(i<m) dp[i] = 1;
        else if(i==m) dp[i] = 2;
        else dp[i] = dp[i-1] + dp[i-m];
    }
    
    cout<<dp[n]<<"\n";
    
    return 0;
}