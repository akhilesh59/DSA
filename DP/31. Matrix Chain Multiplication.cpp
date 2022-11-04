// 1. Memoization:
/*
class Solution{
private:
    
    vector<vector<int>> dp;
    int recur(int arr[], int i, int j) {
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        
        for(int k=i; k<j; ++k) {
            int tmp = arr[i-1]*arr[k]*arr[j] + recur(arr, i, k) + recur(arr, k+1, j);
            mini = min(mini, tmp);
        }
        
        return dp[i][j] = mini;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        dp = vector<vector<int>> (N+1, vector<int>(N+1, -1));
        return recur(arr, 1, N-1);
    }
};
*/

// 2. Tabulation
class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
        
        for(int i=N-1; i>=1; --i) {
            for(int j=i+1; j<N; ++j) {
                int mini = INT_MAX;
                for(int k=i; k<j; ++k) {
                    int tmp = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini, tmp);
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[1][N-1];
    }
};