class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        
        for(int i=0; i<n; i++) {
            // vector<int> tmp = {1};
            // vector<int> last = ans.back();
            // int idx = 1;
            // if(last.size() > 1) {
            //     for(int j=1; j<last.size(); j++) {
            //         int x = last[j]+last[j-1];
            //         tmp.push_back(x);
            //     }
            // }
            // tmp.push_back(1);
            // ans.push_back(tmp);
            
            // Space Optimized:
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
            
            for(int j=1; j<i; j++) {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        
        return ans;
    }
};