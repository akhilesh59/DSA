class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.length(), maxi = 0, x = -1, y = -1;
        vector<vector<bool>> dp(n+1, vector<bool>(n+1,0));
        
        for(int gap=0; gap<n; ++gap) {
            for(int i=0, j=gap; j<n; ++i, ++j) {
                if(gap == 0) {
                    dp[i][j] = 1;
                }
                else if(gap == 1) {
                    if(s[i] == s[j]) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
                else {
                    if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                    else dp[i][j] = 0;
                }
                
                if(dp[i][j] == 1 && maxi < gap+1) {
                    maxi = gap+1;
                    x = i, y = j;
                }
            }
        }
        
        ans = s.substr(x, maxi);
        
        return ans;
    }
};