class Solution {
    
public:
    int maxProfit(vector<int>& p) {
        
        int n = p.size();
        
        // For L -> R Traversal :
        int mpist = 0; //mpist max_profit_if_sold_today
        int least = p[0];
        vector<int> dpl(n+1); // dp for left to right traversal
        
        for(int i=1; i<n; i++) {
            if(least > p[i]) {
                least = p[i];
            }
            
            mpist = p[i] - least;
            dpl[i] = max(dpl[i-1], mpist);
        }
        
        // For Right to Left Traversal:
        
        int mpibt = 0; // mpibt max_profit_if_bought_today
        int maxSP = p[n-1];
        vector<int> dpr(n+1);
        
        for(int i=n-2; i>=0; i--) {
            if(maxSP < p[i]) {
                maxSP = p[i];
            }
            
            mpibt = maxSP - p[i];
            dpr[i] = max(dpr[i+1], mpibt);
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            ans = max(ans, dpl[i]+dpr[i]);
        }
        
        return ans;
        
    }
};