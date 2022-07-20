class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> ans;
        int n = v.size();
        sort(v.begin(), v.end());
        
        for(int i=0; i<n; ++i) {
            if(i>0) while(i<n && v[i] == v[i-1]) ++i;
            int j = i+1, k = n-1;
            while(j<k) {
                if(v[i] + v[j] + v[k] == 0) {
                    ans.push_back({v[i], v[j], v[k]});
                    ++j, --k;
                    while(j<n && v[j] == v[j-1]) ++j;
                    while(k>=0 && v[k] == v[k+1]) --k;
                }
                else if(v[i] + v[j] + v[k] > 0) --k;
                else ++j;
            }
        }
        
        return ans;
        
    }
};