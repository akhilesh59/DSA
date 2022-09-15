class Solution{
private:
    
    vector<int> a = {1,0,-1,0};
    vector<int> b = {0,-1,0,1};
    vector<char> vc = {'D','L','U','R'};


    bool isSafe(vector<vector<int>> &m, int n, int i, int j, vector<vector<int>>& vis) {
        if(i>=0 && i<n && j>=0 && j<n) {
            if(!vis[i][j] &&  m[i][j] == 1) return true;
        }
        return false;
    }
    
    void dfs(vector<vector<int>> &m, int n, int i, int j, string& ssf, vector<string>& ans, vector<vector<int>>& vis) {
        if(i == n-1 && j == n-1) {
            ans.push_back(ssf);
            return;
        }
        
        vis[i][j] = 1;
        
        for(int k=0; k<4; ++k) {
            int di = i + a[k], dj = j + b[k];
            if(isSafe(m, n, di, dj, vis)) {
                vis[di][dj] = 1;
                ssf.push_back(vc[k]);
                
                dfs(m, n, di, dj, ssf, ans, vis);
                
                ssf.pop_back();
                vis[di][dj] = 0;
            }
        }
        
        return;
        
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n,0));
        string ssf = "";
        
        if(m[0][0] == 0 || m[n-1][n-1] == 0) return ans;
        
        dfs(m, n, 0, 0, ssf, ans, vis);
        
        return ans;
        
    }
};