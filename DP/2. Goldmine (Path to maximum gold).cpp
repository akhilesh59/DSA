class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans = INT_MIN;
        vector<vector<int>> dp(n,vector<int>(m));
        
        for(int i=0; i<n; i++) dp[i][m-1] = M[i][m-1];
        
        for(int j=m-2; j>=0; j--) {
            for(int i = 0; i<n; i++) {
                if(i-1 >= 0 && i+1 < n) {
                    dp[i][j] = M[i][j] + max(max(dp[i-1][j+1], dp[i][j+1]), dp[i+1][j+1]);
                }
                else if(i-1 < 0 && i+1 >= n) {
                    dp[i][j] = M[i][j] + dp[i][j+1];
                }
                else if(i-1 < 0) {
                    dp[i][j] = M[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
                }
                else {
                    dp[i][j] = M[i][j] + max(dp[i][j+1], dp[i-1][j+1]);
                }
            }
        }
        
        for(int i=0; i<n; i++) ans = max(ans, dp[i][0]);
        
        return ans;
    }
};