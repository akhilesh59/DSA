class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], maxi = 0;
        for(auto it : prices) {
            int curr = it-buy;
            maxi = max(maxi, curr);
            if(curr<0) buy = it;
        }
        
        return maxi;
    }
};