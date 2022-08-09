class Solution {
private:
    void recur(int n, vector<int>& v, vector<vector<int>>& ans, vector<int> tmp, int idx) {
        ans.push_back(tmp);
        for(int i=idx; i<n; ++i) {
            if(i != idx && v[i] == v[i-1]) continue;
            tmp.push_back(v[i]);
            recur(n, v, ans, tmp, i+1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        recur(n, nums, ans, {}, 0);
        return ans;
    }
};