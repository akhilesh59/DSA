class Solution{
    public:
    int maxLen(vector<int>&v, int n)
    {   
        unordered_map<int,int> mp;
        int sum_so_far = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
           sum_so_far += v[i];
           if(sum_so_far == 0) {
               ans = i+1;
           }
           else if(mp.find(sum_so_far) != mp.end()) {
               ans = max(ans, i-mp[sum_so_far]);
           }
           else {
               mp[sum_so_far] = i;
           }
        }
        
        return ans;
    }
};