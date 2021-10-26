class Solution{

  public:
  
	int minDifference(int arr[], int n)  { 
	    int mini = INT_MAX;
	    int sum = 0;
	    for(int i=0; i<n; i++) sum += arr[i];
	    bool dp[n+1][sum+1];
	    memset(dp, false, sizeof(dp));
	    dp[0][0] = true;
	    
	    for(int i=1; i<=n; i++) {
	        for(int j=0; j<=sum/2; j++) {
	            if(j == 0) dp[i][j] = true;
	            else {
	                if(j >= arr[i-1]) {
	                    dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
	                }
	                else dp[i][j] = dp[i-1][j];
	            }
	            
	            if(dp[i][j]) mini = min((sum - 2*j), mini);
	        }
	    }
	    
	    return mini;
	} 
};
