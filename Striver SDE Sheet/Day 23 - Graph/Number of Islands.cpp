class Solution {
private:
    vector<int> a = {1,0,-1,0};
    vector<int> b = {0,1,0,-1};
    
    static bool isSafe(int i, int j, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(i<m && i>=0 && j<n && j>=0) return 1;
        return 0;
    }
    
    bool dfs(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == '0') return false;
        grid[i][j] = '0';
        
        bool res = false;
        
        for(int k=0; k<4; ++k) {
            int x = a[k] + i, y = b[k] + j;
            if(isSafe(x,y,grid)) res |= dfs(grid, x, y);
        }
        return true;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(dfs(grid, i, j)) ++count;
            }
        }
        
        return count;
    }
};