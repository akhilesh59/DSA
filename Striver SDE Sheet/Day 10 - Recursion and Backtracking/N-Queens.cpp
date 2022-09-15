class Solution {
private:
    vector<vector<string>> ans;
    
    static bool isSafe(vector<vector<int>>& mat, int n, int row, int col) {
        // Vertical Cancellation Check:
        for(int i=row; i>=0; --i) {
            if(mat[i][col] == 1) return false;
        }
        
        // Left Diagonal Check:
        for(int i=row, j=col; i>=0 && j>=0; --i, --j) {
            if(mat[i][j] == 1) return false;
        }
        
        // Right Diagonal Check:
        for(int i=row, j=col; i>=0 && j<n; --i, ++j) {
            if(mat[i][j] == 1) return false;
        }
        
        return true;
    }
    
    void recur(int n, vector<vector<int>>& mat, vector<string>& op, int row) {
        if(row == n) {
            ans.push_back(op);
            return;
        }
        
        for(int i=0; i<n; ++i) {
            if(isSafe(mat, n, row, i)) {
                mat[row][i] = 1;
                op[row][i] = 'Q';
                
                recur(n, mat, op, row+1);
                
                mat[row][i] = 0;
                op[row][i] = '.';
            }
        }
        
        return;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> mat(n, vector<int>(n,0));
        
        vector<string> op(n);
        string tmp(n,'.');
        
        for(int i=0; i<n; ++i) op[i] = tmp;
        
        recur(n, mat, op, 0);
        
        return ans;
        
    }
};