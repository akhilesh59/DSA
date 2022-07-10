class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int col = false;
        
        for(int i=0; i<m; i++) {
            if(mat[i][0] == 0) col = 1;
            for(int j=1; j<n; j++) {
                if(mat[i][j] == 0) mat[0][j] = mat[i][0] = 0; 
            }
        }
        
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=1; j--) {
                if(!(mat[0][j] && mat[i][0])) mat[i][j] = 0;
            }
            if(col) mat[i][0] = 0;
        }

    }
};