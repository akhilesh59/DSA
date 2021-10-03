#include<iostream>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    
    if(n==0 || k==0 || n<k) {
        cout<<0<<"\n";
        return 0;
    }
    
    long long dp[k+1][n+1];
    
    for(int i=0; i<=k; i++) {
        for(int j=0; j<=n; j++) {
            
            if(i == 0 || j == 0) dp[i][j] = 0;
            
            else if(i == 1) dp[i][j] = 1;
            
            else if(i > j) dp[i][j] = 0;
            
            else if(i == j) dp[i][j] = 1;
            
            else {
                dp[i][j] = i*(dp[i][j-1]) + dp[i-1][j-1];
            }
        }
    }
    
    cout<<dp[k][n]<<"\n";
    
    return 0;
}