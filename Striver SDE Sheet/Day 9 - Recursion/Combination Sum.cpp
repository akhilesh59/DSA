class Solution {
private:
    void solve(vector<vector<int>>& ans, vector<int>& arr, vector<int>& v, int idx, int ssf, int &t) {
        if(idx == arr.size() || ssf > t) return;
        if(ssf == t) {
            ans.push_back(v);
            return;
        }
        
        v.push_back(arr[idx]);  // include the current index
        solve(ans, arr, v, idx, ssf+arr[idx], t);  // Call for the current index again and again
        v.pop_back();  // Backtrack if it hits the base case
        
        solve(ans, arr, v, idx+1, ssf, t);  // Call for the next index without including the current index
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int t) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(ans, arr, v, 0, 0, t);
        return ans;
    }
};

//------------------------- Another Solution ----------------------//

class Solution {
private:
    
    void recur(vector<int>& v, int t, vector<vector<int>>& ans, vector<int> tmp, int ssf, int idx) {
        if(ssf >= t) {
            if(ssf == t) ans.push_back(tmp);
            return;
        }
        
        for(int i=idx; i<v.size(); ++i) {
            tmp.push_back(v[i]);
            recur(v, t, ans, tmp, ssf+v[i], i);
            tmp.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        
        vector<vector<int>> ans;
        vector<int> tmp;
        
        recur(v, t, ans, tmp, 0, 0);
        
        return ans;
        
    }
};