/*
// 1. Memoization:
class Solution {
private:
    vector<vector<int>> dp;
    int recur(vector<int>& v, int i, int j) {
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi = INT_MIN;
        
        for(int k=i; k<=j; ++k) {
            int cost = v[i-1]*v[k]*v[j+1] + recur(v, i, k-1) + recur(v, k+1, j);
            maxi = max(cost, maxi);
        }
        
        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& v) {
        int n = v.size();
        dp = vector<vector<int>>(n+1, vector<int>(n+1,-1));
        
        v.push_back(1);
        v.insert(v.begin(), 1);
        
        return recur(v, 1, n);
    }
};
*/

// 2. Tabulation:
class Solution {
public:
    int maxCoins(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+5, vector<int>(n+5,0));
        // here we have initialized dp with zero to cover the base case of the recursive approach.
        
        v.push_back(1);
        v.insert(v.begin(), 1);
        
        for(int i=n; i>=1; --i) {
            for(int j=i; j<=n; ++j) {
                int maxi = INT_MIN;
                for(int k=i; k<=j; ++k) {
                    int cost = v[i-1]*v[k]*v[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(cost, maxi);
                }
                dp[i][j] = maxi;
            }
        }
        
        return dp[1][n];
    }
};