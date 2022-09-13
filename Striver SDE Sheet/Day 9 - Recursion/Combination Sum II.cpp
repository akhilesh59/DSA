class Solution {
private:
    
    void recur(vector<int>& v, int t, vector<vector<int>>& ans, vector<int> tmp, int ssf, int idx) {
        if(ssf >= t) {
            if(ssf == t) ans.push_back(tmp);
            return;
        }
        
        for(int i=idx; i<v.size(); ++i) {
            if(i != idx && v[i] == v[i-1]) continue;
            tmp.push_back(v[i]);
            recur(v, t, ans, tmp, ssf+v[i], i+1);
            tmp.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
        vector<vector<int>> ans;
        vector<int> tmp;
        
        sort(v.begin(), v.end());
        
        recur(v, t, ans, tmp, 0, 0);
        
        return ans;
    }
};

