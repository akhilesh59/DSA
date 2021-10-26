class Solution {
public:
    int findTargetSumWays(vector<int>& v, int target) {
        int sum = 0;
        vector<int> tmp;
        int cnt = 0;
        
        for(auto i : v) {
            sum += i;
            if(i == 0) cnt++;
            else tmp.push_back(i);
        }
        
        int n = tmp.size();
        
        if((sum+target)%2 != 0 || (sum + target) < 0) return 0;
        
        int k = (sum + target)/2;
        
        int dp[n+1][k+1];
        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = 1;
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=k; j++) {
                
                if(j == 0) dp[i][j] = 1;
                else {
                    if(j >= tmp[i-1]) {
                        dp[i][j] = dp[i-1][j - tmp[i-1]] + dp[i-1][j];
                    }
                    else dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        
        return (1<<cnt) * dp[n][k];
        
    }
};