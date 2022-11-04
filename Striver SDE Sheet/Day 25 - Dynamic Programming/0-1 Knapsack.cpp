class Solution
{
private:
    /*
    vector<vector<int>> dp;

    int recur(int W, int wt[], int val[], int idx, int& n) {
        if(idx == 0) {
            if(W >= 0) return val[0];
            return 0;
        }
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        int take=0, notTake = 0;
        if(W >= wt[idx]) take = val[idx] + recur(W-wt[idx], wt, val, idx-1, n);
        notTake = recur(W, wt, val, idx-1, n);
        
        return dp[idx][W] = max(take, notTake); 
    }
    */
    
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    {
        // ------------------------- Memoization : ---------------------------------//
        
    //   dp = vector<vector<int>> (n+1, vector<int>(W+1, -1));
    //   return recur(W, wt, val, 0, n);
    
        // ------------------------- Tabulation : ---------------------------------//
        /*
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        
        for(int i=wt[0]; i<=W; ++i) dp[0][i] = val[0];
        
        for(int i=1; i<n; ++i) {
            int take=0, notTake = 0;
            for(int j=0; j<=W; ++j) {
                take = INT_MIN;
                if(j >= wt[i]) take = val[i] + dp[i-1][j-wt[i]];
                notTake = dp[i-1][j];
                
                dp[i][j] = max(take, notTake);
            }
        }
        
        return dp[n-1][W];
        */
        
        // --------------- Tabulation with Space Optimization (2 Vectors) : -------------------------//
        /*
        vector<int> curr(W+1,0), prev(W+1,0);
        
        for(int i=wt[0]; i<=W; ++i) prev[i] = val[0];
        
        for(int i=1; i<n; ++i) {
            int take=0, notTake = 0;
            for(int j=0; j<=W; ++j) {
                take = INT_MIN;
                if(j >= wt[i]) take = val[i] + prev[j-wt[i]];
                notTake = prev[j];
                
                curr[j] = max(take, notTake);
            }
            prev = curr;
        }
        
        return prev[W];
        */
        
        // --------------- Tabulation with Space Optimization (1 Vector) : -------------------------//
        
        vector<int> prev(W+1,0);
        
        for(int i=wt[0]; i<=W; ++i) prev[i] = val[0];
        
        for(int i=1; i<n; ++i) {
            int take=0, notTake = 0;
            for(int j=W; j>=0; --j) {
                take = INT_MIN;
                if(j >= wt[i]) take = val[i] + prev[j-wt[i]];
                notTake = prev[j];
                
                prev[j] = max(take, notTake);
            }
        }
        
        return prev[W];
    }
};