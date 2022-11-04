class Solution {
private:
    vector<vector<int>> dp;
    
//     int recur(vector<int>& v, int idx, int prev_idx) {
//         if(idx == v.size()) return 0;
        
//         if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];
        
//         int len = recur(v, idx+1, prev_idx); // not pick
        
//         if(prev_idx == -1 || v[idx] > v[prev_idx]) {
//             int len2 = 1 + recur(v, idx+1, idx);
//             len = max(len, len2);
//         }
        
//         return dp[idx][prev_idx+1] = len;
//     }
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();

//----------------------------- Memoization: --------------------------
        
        // dp = vector<vector<int>> (n+1, vector<int>(n+1, -1));        
//         int ans = recur(v, 0, -1);        
//         return ans;
        
        // Tabulation :
        
//         dp = vector<vector<int>> (n+1, vector<int>(n+1, 0));
        
//         for(int idx = n-1; idx >= 0; --idx) {
//             for(int prev_idx = idx-1; prev_idx >= -1; --prev_idx) {
//                 int len = dp[idx+1][prev_idx+1]; // not pick

//                 if(prev_idx == -1 || v[idx] > v[prev_idx]) {
//                     int len2 = 1 + dp[idx+1][idx+1];
//                     len = max(len, len2);
//                 }
                
//                 dp[idx][prev_idx+1] = len;
//             }
//         }
        
//         return dp[0][-1+1];
        
// ------------------  //Tabulation with Space Optimization : -------------------//
        
//         vector<int> curr(n, 0), next(n+1, 0);
        
//         for(int idx = n-1; idx >= 0; --idx) {
//             for(int prev_idx = idx-1; prev_idx >= -1; --prev_idx) {
//                 int len = next[prev_idx+1]; // not pick

//                 if(prev_idx == -1 || v[idx] > v[prev_idx]) {
//                     int len2 = 1 + next[idx+1];
//                     len = max(len, len2);
//                 }
                
//                 curr[prev_idx+1] = len;
//             }
//             next = curr;
//         }
        
//         return curr[0];
        

// --------------------------- Printing the LIS : --------------------------------//
        
//         vector<int> dp(n, 1), hash(n);
        
//         for(int i=0; i<n; ++i) hash[i] = i;
        
//         int maxi = 1, lastIndex = 0;
        
//         for(int i=0; i<n; ++i) {
//             for(int prev=0; prev<i; ++prev) {
//                 if(v[i] > v[prev] && (1+dp[prev] > dp[i])) {
//                     dp[i] = 1+dp[prev];
//                     hash[i] = prev;
//                 }
//             }
//             if(dp[i] > maxi) {
//                 maxi = dp[i];
//                 lastIndex = i;                
//             }                
//         }
        
//         vector<int> res(maxi);
//         int idx = 1;
        
//         res[0] = v[lastIndex];
        
//         while(lastIndex != hash[lastIndex]) {
//             lastIndex = hash[lastIndex];
//             res[idx++] = v[lastIndex];
//         }
        
//         reverse(res.begin(), res.end());
        
//         for(auto it : res) cout<<it<<' ';
//         cout<<'\n';
        
//         return maxi;
        
        
// ---------------------------- Binary Search : ---------------------------------//
        
        vector<int> tmp;
        tmp.push_back(v[0]);
        
        int maxLen = 1;
        
        for(int i=1; i<n; ++i) {
            if(tmp.back() < v[i]) {
                tmp.push_back(v[i]);
                maxLen++;
            }
            else {
                int idx = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
                tmp[idx] = v[i];
            }
        }
        
        return maxLen;
        
    }
};