class Solution {    
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        if(n == 1) return v[0];
        
        // int n = nums.size(), maxi = 1, mini = 1, ans = INT_MIN;
        
        // for(int i=0; i<n; ++i) {
        //     if(nums[i] < 0) swap(mini, maxi);
            
        //     maxi = max(nums[i], maxi*nums[i]);
        //     mini = min(nums[i], mini*nums[i]);
        //     ans = max(ans, maxi);
        // }
        
        // Second approach:
        
        int ans = INT_MIN, prod = 1;
        
        for(int i=0; i<n; i++) {
            prod *= v[i];
            ans = max(ans,prod);
            if(prod == 0) prod = 1;
        }
        prod = 1;
        for(int i=n-1; i>=0; i--) {
            prod *= v[i];
            ans = max(ans,prod);
            if(prod == 0) prod = 1;
        }
        
        return ans; 
    }
};