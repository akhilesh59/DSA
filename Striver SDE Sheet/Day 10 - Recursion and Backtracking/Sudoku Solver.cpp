class Solution {
private:
    vector<vector<char>> ans;
    
    static bool isValid(vector<vector<char>>& mat, int row, int col, char ch) {
        // Checking the row:
        for(int j=0; j<9; ++j) {
            if(mat[row][j] == ch) return false;
        }
        
        // Checking for Column:
        for(int i=0; i<9; ++i) {
            if(mat[i][col] == ch) return false;
        }
        
        // Checking for 3x3 Sub-grid:
        int ri = (row/3)*3;
        int cj = (col/3)*3;
        
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j) {
                if(mat[ri + i][cj + j] == ch) return false;
            }
        }
        
        return true;
    }
    
    void recur(vector<vector<char>>& mat, int row, int col) {
        if(row == 9) {
            ans = mat;
            return;
        }
        
        int next_r = -1, next_c = -1;
        
        if(col == 8) {
            next_r = row+1;
            next_c = 0;
        }
        else {
            next_r = row;
            next_c = col+1;
        }
        
        if(mat[row][col] != '.') {
            recur(mat, next_r, next_c);
        }            
        else {
            for(char ch = '1'; ch <= '9'; ++ch) {
                if(isValid(mat, row, col, ch)) {
                    mat[row][col] = ch;
                    
                    recur(mat, next_r, next_c);
                    
                    mat[row][col] = '.';
                }
            }
        }
        
        return;
        
    }
    
public:
    void solveSudoku(vector<vector<char>>& mat) {
        recur(mat, 0, 0);
        mat = ans;
    }
};