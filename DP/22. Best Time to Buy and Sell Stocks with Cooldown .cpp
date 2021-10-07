class Solution {
private:
    
    int findMaxProfit(vector<int>& p,vector<int>& memo, int curr) {
        if(curr >= p.size()) return 0;
        
        if(memo[curr] != -1) return memo[curr];
        
        //Find all the position where we can sell the curr bought stock:
        int maxReturn = 0;
        
        for(int i=curr+1; i<p.size(); i++) {
            if(p[i] > p[curr]) {
            // We will decide to sell this stock on this i'th day and check for all the profit on the upcoming days with a agap of one day to maintain the cooldown period.
                maxReturn = max(maxReturn, p[i]-p[curr] + findMaxProfit(p,memo,i+2));
            }
            
        }
        // If we decide not to choose the curr stock:
        
        maxReturn = max(maxReturn, findMaxProfit(p,memo, curr+1));
        
        // Store this curr ka ans in the memo before returning:
        return memo[curr] = maxReturn;
        
        // return maxReturn;
        
    }
    
public:
    int maxProfit(vector<int>& prices) {
        vector<int> memo(prices.size()+1,-1);
        int ans = findMaxProfit(prices,memo, 0);
        return ans;
        
    }
};