class Solution{
public:
	int maxSumIS(int v[], int n)  
	{
	    vector<int> dp(n, 1);
        
        int maxi = *max_element(v, v+n);
        
        for(int i=0; i<n; ++i) {
            dp[i] = v[i];
            for(int prev=0; prev<i; ++prev) {
                if(v[i] > v[prev] && (v[i]+dp[prev] > dp[i])) {
                    dp[i] = v[i]+dp[prev];
                }
            }
            maxi = max(dp[i], maxi);                
        }
        
        return maxi;
	}  
};