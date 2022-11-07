/*
// 1. Memoization:
class Solution {
private:
    vector<vector<int>> dp;
    static bool isSafe(vector<vector<int>>& mat, int i, int j) {
        int n = mat.size(), m = mat[0].size();        
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    int recur(vector<vector<int>>& mat, int i, int j) {
        int n = mat.size(), m = mat[0].size();
        if(!isSafe(mat, i, j)) return INT_MAX;
        if(i == n-1 && j == m-1) {
            return mat[i][j];
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        int curr = mat[i][j];
        
        int down = recur(mat, i+1, j);
        int right = recur(mat, i, j+1);
        
        return dp[i][j] = curr + min(down, right);
    }
public:
    int minPathSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        dp = vector<vector<int>> (n+1, vector<int>(m+1, -1));
        
        return recur(mat, 0, 0); 
    }
};
*/

/*
// 2. Tabulation:
class Solution {
public:
    int minPathSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[n-1][m-1] = mat[n-1][m-1];
        for(int j=0; j<m; ++j) dp[n][j] = INT_MAX;
        for(int i=0; i<n; ++i) dp[i][m] = INT_MAX;
        
        for(int i=n-1; i>=0; --i) {
            for(int j=m-1; j>=0; --j) {
                if(i == n-1 && j == m-1) continue;
                dp[i][j] = mat[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        return dp[0][0]; 
    }
};
*/

// 3. Tabulation with Space Optimization:
class Solution {
public:
    int minPathSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> curr(m+1), next(m+1, INT_MAX);
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        curr[m-1] = mat[n-1][m-1];
        
        
        for(int i=n-1; i>=0; --i) {
            curr[m] = INT_MAX;
            for(int j=m-1; j>=0; --j) {
                if(i == n-1 && j == m-1) continue;
                curr[j] = mat[i][j] + min(next[j], curr[j+1]);
            }
            next = curr;
        }
        
        return curr[0]; 
    }
};
