class Solution {
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
    
public:
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> left;
        vector<int> right;
        int n = heights.size();
        
        nsl(heights, left);
        nsr(heights, right);
        
        // for(auto it : left) cout<<it<<' ';
        // cout<<'\n';
        // for(auto it : right) cout<<it<<' ';
        // cout<<'\n';
        
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++) {
            int area=0,w=0,h=heights[i];
            w += (left[i] == -1) ? i+1 : i-left[i] ;
            w += (right[i] == -1) ? n-i-1 : right[i]-i-1;
            
            area = w*h;
            ans = max(ans, area);
            
            // cout<<area<<' ';
        }
        
        return ans;
        
    }
};