class Solution {
private: 
    
    // RECURSIVE FUNCTION :
    
//     bool helper(vector<int>& v, int idx, int& tar, int ssf) {
//         if(idx >= v.size()) return false;
        
//         if(ssf == tar) return true;
        
//         bool c1 = helper(v,idx+1, tar, ssf+v[idx]);
//         bool c2 = helper(v,idx+1, tar, ssf);
        
//         return (c1 || c2);
//     }
    
public:
    bool canPartition(vector<int>& v) {
        
        int sum = 0;
        for(auto i : v) sum += i;
        
        if(sum%2 != 0) {
            return false;
        }
        
        int tar = sum/2;
        int n = v.size();
        bool dp[n+1][tar+1];
        memset(dp,false, sizeof(dp));
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=tar; j++) {
                if(j == 0) dp[i][j] = true;
                else {
                    if(j - v[i-1] >= 0) {
                        dp[i][j] = (dp[i-1][j-v[i-1]] || dp[i-1][j]);
                    }
                    else dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][tar];
        
        
        
        // return helper(v,0,tar,0);   RECURSIVE function call
        
    }
};