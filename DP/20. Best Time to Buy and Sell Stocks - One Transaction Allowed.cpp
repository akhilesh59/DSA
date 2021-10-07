class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int least_price = INT_MAX;
        int max_profit = 0;
        int profit_today = 0;
        
        for(auto i : prices) {
            if(i < least_price) {
                least_price = i;
            }
            
            profit_today = i-least_price;
            max_profit = max(max_profit, profit_today);
        }
        
        return max_profit;
        
    }
};