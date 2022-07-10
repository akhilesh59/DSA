class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = (int)mat.size();
        vector<vector<int>> tmp(n, vector<int>(n));
        
        for(int j=n-1; j>=0; j--) {
            for(int i=n-1; i>=0; i--) {
                tmp[j][n-1-i] = mat[i][j];
            }
        }
        mat = tmp;        
    }
};