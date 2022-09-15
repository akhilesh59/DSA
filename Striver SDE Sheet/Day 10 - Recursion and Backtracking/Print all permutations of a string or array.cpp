class Solution {
vector<vector<int>> ans;

private : 
    
    void helper(vector<int>& arr, int& n, int curr, vector<int> v, map<int,bool>& mp) {
        if(v.size() == n) {
            ans.push_back(v);
            return;
        }
        
        for(int i=0; i<n; i++) {
            if(!mp[arr[i]]) {
                v.push_back(arr[i]);
                mp[arr[i]] = 1;
                helper(arr,n,i,v,mp);
                v.pop_back();
                mp[arr[i]] = 0;
            }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& arr) {
        int n = arr.size();
        map<int,bool> mp;
        helper(arr,n,-1,{}, mp);
        return ans;
    }
};