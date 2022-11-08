/*
// 1. Memoization:
class Solution
{
private:
    vector<vector<int>> dp;
    
    int recur(int egg, int f) {
        if(egg == 1) return f;
        if(f <= 1) return f;
        
        if(dp[egg][f] != -1) return dp[egg][f];
        
        int mini = INT_MAX;
        for(int k=1; k<=f; ++k) {
            // Case 1: if egg breaks -> recur(egg-1, k-1) i.e. go downwards
            // Case 2: if egg does not break -> recur(egg, f-k) i.e. go upwards
            int drop_here = 1 + max(recur(egg-1, k-1), recur(egg, f-k));
            mini = min(mini, drop_here);
        }
        
        return dp[egg][f] = mini;
    }
public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        dp = vector<vector<int>>(n+1, vector<int>(k+1, -1));
        return recur(n, k);
    }
};
*/

// 2. Tabulation:
class Solution
{
public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        
        for(int j=0; j<=k; ++j) dp[1][j] = j;
        for(int i=1; i<=n; ++i) dp[i][1] = 1;
        
        for(int egg=2; egg<=n; ++egg) {
            for(int f=1; f<=k; ++f) {
                int mini = INT_MAX;
                for(int k=1; k<=f; ++k) {
                    // Case 1: if egg breaks -> recur(egg-1, k-1) i.e. go downwards
                    // Case 2: if egg does not break -> recur(egg, f-k) i.e. go upwards
                    int drop_here = 1 + max(dp[egg-1][k-1], dp[egg][f-k]);
                    mini = min(mini, drop_here);
                }
                
                dp[egg][f] = mini;
            }
        }
        
        return dp[n][k];
    }
};