class Solution
{
private :

    void recur(vector<int>& v, int n, int idx, int ssf, vector<int>& ans) {
        if(idx > n) return;
        if(idx == n) {
            ans.push_back(ssf);
            return;
        }
        
        recur(v, n, idx+1, ssf+v[idx], ans);
        recur(v, n, idx+1, ssf, ans);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        recur(arr, N, 0, 0, ans);
        return ans;
    }
};