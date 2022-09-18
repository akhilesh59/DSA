int count_smaller(vector<vector<int>> &mat, int num) {
    int cnt = 0;
    for(int i=0; i<mat.size(); ++i) {
        int low = 0, high = mat[i].size()-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(mat[i][mid] <= num) low = mid+1;
            else high = mid-1;
        }
        cnt += low;
    }
    return cnt;
}

int getMedian(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    int low = 1, high = 1e5+5;
    int lim = (n*m)/2;
    while(low <= high) {
        int mid = low + (high-low)/2;
        int x = count_smaller(mat, mid);
        if(x <= lim) {
            low = mid+1;
        }
        else high = mid-1;
    }
    
    return low;
}