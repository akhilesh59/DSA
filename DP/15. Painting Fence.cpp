class Solution{
    public:
    long long countWays(int n, int k){
        long long mod = 1e9+7;
        
        if(n==1) return k;
        
        int dp[2][n];
        // The 1st row will have the count for same color as applied on previous
        // and the 2nd row will count for differsent color from the previous for ith house
        memset(dp,0,sizeof(dp));
        
        dp[0][1] = k; // 1st house ko k tariko se paint kar sakte hai to 2nd house me same
        // rakhne k liye pichle walo me jo color tha wahi color chipka denge 2nd house me
        // to aisa karne k bhi sirf k tarik hi honge
        dp[1][1] = k*(k-1); // 1st house ko kisi bhi tarike se paint karne ke 'k' tarike hi hai
        // to different color combination banane k liye pichle walo me ek different color 
        // laga ke new combination banane k k*(k-1) tarike honge.
        
        
        for(int j=2; j<n; j++) {
            dp[0][j] = dp[1][j-1];
            dp[1][j] = (((dp[0][j-1] + dp[1][j-1])%mod)*(k-1))%mod;
            // pichle house k total tariko ko (k-1) se multiply kar k saari combinations
            // nikal sakte hai jinme color repeat nhi hoga.
        }
        
        int ans = (dp[0][n-1] + dp[1][n-1])%mod;
        
        return ans;
    }
};