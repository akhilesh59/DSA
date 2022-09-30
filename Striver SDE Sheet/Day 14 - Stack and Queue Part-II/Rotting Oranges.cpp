class Solution {
vector<int> a = {-1,0,1,0};
vector<int> b = {0,-1,0,1};
    
private:
    
    bool isSafe(vector<vector<int>>& mat, int i, int j) {
        int m = mat.size(), n = mat[0].size();
        
        return (i>=0 && j>=0 && i<m && j<n && mat[i][j] == 1);
    }
    
public:
    int orangesRotting(vector<vector<int>>& g) {
        int ans = 0;
        int m = g.size(), n = g[0].size();
        queue<pair<int,int>> q;
        bool rem = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(g[i][j] == 2) q.push({i,j});
                else if(g[i][j] == 1) rem = 1;
            }
        }
        
        if(q.empty() && rem) return -1;
        else if(q.empty()) return 0;
        
        while(!q.empty()) {
            int sz = q.size();
            
            for(int i=0; i<sz; i++) {
                auto it = q.front(); q.pop();
                int x = it.first, y = it.second;
                
                for(int j=0; j<4; j++) {
                    if(isSafe(g, x+a[j], y+b[j])) {
                        g[x+a[j]][y+b[j]] = 2;
                        q.push({x+a[j], y+b[j]});
                    }
                }
            }
            
            ans++;
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(g[i][j] == 1) return -1;
            }
        }
        
        return --ans;
        
    }
};