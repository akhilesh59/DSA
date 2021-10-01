int Solution::solve(vector<vector<int> > &a) {

    int n = a.size();

    int dp[3][n];
    memset(dp,0,sizeof(dp));

    dp[0][0] = a[0][0];
    dp[1][0] = a[0][1];
    dp[2][0] = a[0][2];

    for(int i=1; i<n; i++) {
        dp[0][i] = a[i][0] + min(dp[1][i-1], dp[2][i-1]);
        dp[1][i] = a[i][1] + min(dp[0][i-1], dp[2][i-1]);
        dp[2][i] = a[i][2] + min(dp[0][i-1], dp[1][i-1]);
    }

    return min({dp[0][n-1], dp[1][n-1], dp[2][n-1]});

}
