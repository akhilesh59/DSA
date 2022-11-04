/*
// 1. Memoization:
class Solution {
private:
    vector<vector<int>> dp;
    int recur(string& s1, string& s2, int i, int j) {
        if(i == 0) return j;
        if(j == 0) return i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i-1] == s2[j-1]) return recur(s1, s2, i-1, j-1);

        int insert = 1 + recur(s1, s2, i, j-1);
        int del = 1 + recur(s1, s2, i-1, j);
        int replace = 1 + recur(s1, s2, i-1, j-1);
        
        return dp[i][j] = min({insert, del, replace});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        dp = vector<vector<int>> (n+1, vector<int>(m+1, -1));
        return recur(word1, word2, n, m); // using 1-based indexing
    }
};
*/

/*
// 1. Tabulation:
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>>dp (n+1, vector<int>(m+1, -1));
        // Using 1-based Indexing:
        for(int i=0; i<=n; ++i) dp[i][0] = i;
        for(int j=0; j<=m; ++j) dp[0][j] = j;
        
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    int insert = 1 + dp[i][j-1];
                    int del = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];
                    dp[i][j] = min({insert, del, replace});
                }
                
            }
        }
        
        return dp[n][m]; 
    }
};
*/

// 1. Tabulation with space optimization:
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<int> prev(m+1, -1), curr(m+1, -1);
        // Using 1-based Indexing:

        for(int j=0; j<=m; ++j) prev[j] = j; // 0th row me jo col no. hoga vo fill karna hai
        
        for(int i=1; i<=n; ++i) {
            curr[0] = i; // 0th column me jo row number hoga vo fill karna hai 
            for(int j=1; j<=m; ++j) {
                if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
                else {
                    int insert = 1 + curr[j-1];
                    int del = 1 + prev[j];
                    int replace = 1 + prev[j-1];
                    curr[j] = min({insert, del, replace});
                }
                
            }
            prev = curr;
        }
        
        return prev[m]; 
    }
};