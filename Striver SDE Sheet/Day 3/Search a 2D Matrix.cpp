class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int r = -1, n = mat.size(), m = mat[0].size();
        int low = 0, high = n-1;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(t >= mat[mid][0] && t <= mat[mid][m-1]) {
                r = mid;
                break;
            }
            else if(t < mat[mid][0]) high = mid-1;
            else low = mid+1;
        }
        
        if(r == -1) return 0;
 
        low = 0, high = m-1;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(mat[r][mid] == t) return 1;
            else if(mat[r][mid] > t) high = mid-1;
            else low = mid+1;
        }
        
        return 0;
    }
};