class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	   
	    int dp[n][2];
	    memset(dp,0,sizeof(dp));
	    
	    dp[0][0] = arr[0];
	    dp[1][0] = 0;
	    
	    for(int i=1; i<n; i++) {
	        dp[0][i] = dp[1][i-1] + arr[i];
	        dp[1][i] = max(dp[0][i-1], dp[1][i-1]);
	    }
	    
	    return max(dp[0][n-1], dp[1][n-1]);
	}
};