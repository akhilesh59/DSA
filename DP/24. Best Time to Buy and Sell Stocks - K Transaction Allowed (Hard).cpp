class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        
        int n = p.size();
        if(n == 0 || k == 0) return 0;
        
        int dp[k+1][n];
        
        memset(dp,0,sizeof(dp));
        
        for(int t=1; t<=k; t++) {
            int maxProfit = INT_MIN;
            
            for(int d=1; d<n; d++) {
                maxProfit = max(maxProfit, dp[t-1][d-1] - p[d-1]);
                
                dp[t][d] = max(maxProfit + p[d], dp[t][d-1]);
            }
        }
        
        return dp[k][n-1];
        
    }
};