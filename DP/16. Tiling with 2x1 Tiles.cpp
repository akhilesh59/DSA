#include<iostream>
using namespace std;

int main() {
    int n; cin >> n;
    
    if(n==0 || n==1) {
        cout<<1<<"\n";
        return 0;
    }
    
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout<<dp[n]<<"\n";
    
    
    return 0;
}