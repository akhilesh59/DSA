class Solution{
public:
	#define ll long long
	ll mod = 1e9+7;
	
	ll countStrings(int n) {
	    ll dp[2][n+1] = {0};
	   // memset(dp,0,sizeof(dp));
	    dp[0][1] = 1;
	    dp[1][1] = 1;
	    
	    for(ll i=2; i<=n; i++) {
	        dp[0][i] = ((dp[0][i-1])%mod + (dp[1][i-1])%mod)%mod;
	        dp[1][i] = (dp[0][i-1])%mod;
	    }
	    
	    // Below code is for printing dp array
	    
	   // for(int i=0; i<2; i++) {
	   //     for(int j=0; j<=n; j++) cout<<dp[i][j]<<" ";
	   //     cout<<'\n';
	   // }
	   
	   
	   // 2nd Method : 
	   
	   ll prev0 = 1;
	   ll prev1 = 1;
	   ll curr0 = 1; // curr variables are innitialised to 1 to handle the case for n=1, 
	   ll curr1 = 1; // verna 0 se bhi initialise kar k kaam hal hi jata
	   
	   for(ll i=2; i<=n; i++) {
	       curr0 = (prev0%mod + prev1%mod)%mod;
	       curr1 = prev0%mod;
	       prev0 = curr0;
	       prev1 = curr1;
	   }
	    
	   // return (dp[0][n] + dp[1][n])%mod;
	   
	   return(curr0 + curr1)%mod; // return using the 2nd method
	}
};