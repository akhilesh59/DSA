class Solution {
// private:
//     int lcs(string& x, int i, string& y, int j, vector<vector<int>>& memo) {
//         if(i == x.length() || j == y.length()) return 0;
        
//         if(memo[i][j] != -1) return memo[i][j];
        
//         if(x[i] == y[j]) {
//             memo[i][j] = 1 + lcs(x,i+1,y, j+1, memo);
//             return memo[i][j];
//         }
        
//         memo[i][j] = max(lcs(x,i,y,j+1,memo), lcs(x,i+1,y,j,memo));
        
//         return memo[i][j];
//     }
    
public:
    int longestCommonSubsequence(string s1, string s2) {

// ------------------------- Memoization : ---------------------//
//         int n = s1.size(), m = s2.size();
//         vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
        
//         return lcs(s1, 0, s2, 0, memo);
        
// ----------------------------- Tabulation : ---------------------//
        
//         int n = s1.size(), m = s2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
//         for(int i=1; i<=n; ++i) {
//             for(int j=1; j<=m; ++j) {
//                 if(s1[i-1] == s2[j-1]) {
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 }
//                 else {
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }
        
//         return dp[n][m];
        
    
// ------------------ Tabulation With Space Optimization : ----------------//
        
        int n = s1.size(), m = s2.size();
        vector<int> curr(m+1,0), prev(m+1,0);
        
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                if(s1[i-1] == s2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                }
                else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        
        return prev[m];
    }
};