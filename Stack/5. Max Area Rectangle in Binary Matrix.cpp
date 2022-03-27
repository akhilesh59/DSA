class Solution {
    
    /* Here the whole code for Max Area Histogram will be used. And the logic is simple, just compress the 2D matrix into 1D array and call the MAH code. To compress the 2D matrix, do like this:
    1. copy the 1st row as it is in the 1D array.
    2. Now for the rest of the rows, make a new 1D array in such a manner that, if the element at current index 'idx' is 1(>0) then store the (prev_arr[idx] + 1) in the new array, otherwise leave it to zero. Now pass this array in MAH and store the ans.
    3. Repeat step 2 for all the remaining rows and keep on storing the max value of the area received from MAH.
    
    Note : 
    1. MAH stands for Maximum area Histogram.
    2. nsl : nearest smallest to left.
    3. nsr : nearest smallest to right.
    
    */
    
    /*---------------------- Code for MAH Starts --------------------- */
    
private:
    void nsl(vector<int>& heights, vector<int>& left) {
        stack<pair<int,int>> st;
        
        for(int i=0; i<heights.size(); i++) {
            while(!st.empty() && st.top().first >= heights[i]) st.pop();
            
            if(st.empty()) left.push_back(-1);
            else left.push_back(st.top().second);
            
            st.push({heights[i], i});
        }
    }
    
    void nsr(vector<int>& heights, vector<int>& right) {
        stack<pair<int,int>> st;
        
        for(int i=heights.size()-1; i>=0; i--) {
            while(!st.empty() && st.top().first >= heights[i]) st.pop();
            
            if(st.empty()) right.push_back(-1);
            else right.push_back(st.top().second);
            
            st.push({heights[i], i});
        }
        
        reverse(right.begin(), right.end());
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> left;
        vector<int> right;
        int n = heights.size();
        
        nsl(heights, left);
        nsr(heights, right);
        
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++) {
            int area=0,w=0,h=heights[i];
            w += (left[i] == -1) ? i+1 : i-left[i] ;
            w += (right[i] == -1) ? n-i-1 : right[i]-i-1;
            
            area = w*h;
            ans = max(ans, area);
            
        }
        
        return ans;
        
    }
    
    /*---------------------- Code for MAH Ends ------------------- */
    
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int ans = INT_MIN;
        int n = mat.size(), m = mat[0].size();
        
        vector<int> mask(m,0);
        for(int j=0; j<m; j++) if(mat[0][j] == '1') mask[j] = 1;
        
        ans = largestRectangleArea(mask);
        
        for(int i=1; i<n; i++) {
            vector<int> tmp(m,0);
            for(int j=0; j<m; j++) {
                if(mat[i][j] == '1') tmp[j] = mask[j] + 1;
            }
            mask = tmp;
            
            ans = max(ans, largestRectangleArea(mask));
        }
        
        return ans;
        
    }
};