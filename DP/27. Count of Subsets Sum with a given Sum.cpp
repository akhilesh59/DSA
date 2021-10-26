class Solution{
private:

long long mod = 1e9+7;
long long cnt=0;

public:

	int perfectSum(int arr[], int n, int sum)
	{
	    int dp[n+1][sum+1];
	    memset(dp, 0, sizeof(dp));
	    
	    dp[0][0] = 1;
	    
	    for(int i=1; i<=n; i++) {
	        for(int j=0; j<=sum; j++) {
	            if(j == 0) dp[i][j] = 1;
	            else {
	                if(j >= arr[i-1]) {
	                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]) % mod;
	                }
	                else dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	   // for(int i=0; i<=n; i++) {
	   //     for(int j=0; j<=sum; j++) 
	   //         cout<<dp[i][j]<<" ";
	            
	   //         cout<<"\n";
	   // }
	        
	    
	    return dp[n][sum];
        
	}
	  
};
