// 1. Memoization:
/*
class Solution {
private:
    vector<vector<int>> dp;
    int recur(vector<int>& cuts, int i, int j) {
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        
        for(int k=i; k<=j; ++k) {
            int tmp = (cuts[j+1] - cuts[i-1]) + recur(cuts, i, k-1) + recur(cuts, k+1, j);
            mini = min(mini, tmp);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int len = cuts.size();
        // Add 0 to front of cuts and n to end of cuts because there will be a kind of hypothetical 
        // cut at 0 and n which will help to solve the problem with proper indexing in cuts.
        // j+1 aur i-1 jo use kar rhe hai function me vo tabhi use kar payenge...
        
        // And it is very important to sort the array because when we will break the cuts array into 
        // smaller sub problems then if in any sub problem there is a cut which belongs to the stick 
        // length which is lying in another sub problem so we would not be able to make a cut in this 
        // case. So it is very Important to sort cuts so that all the cuts in a subproblem belongs to 
        // that lenth in the subproblem only. 
        // Refer Striver Video for better Explanation!
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        
        dp = vector<vector<int>>(len+3, vector<int>(len+3, -1));
        return recur(cuts, 1, len);
    }
};
*/

// 2: Tabulation:
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int len = cuts.size();
        // Reason for the below 3 steps is Explained in the above approach:
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        
        vector<vector<int>> dp(len+3, vector<int>(len+3, 0));
        
        for(int i=len; i>=1; --i) {
            for(int j=i; j<=len; ++j) {
                int mini = INT_MAX;
        
                for(int k=i; k<=j; ++k) {
                    int tmp = (cuts[j+1] - cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, tmp);
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[1][len];
    }
};