class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;
//         vector<int> mxl(n); mxl[0] = height[0];
//         vector<int> mxr(n); mxr[n-1] = height[n-1];
        
//         for(int i=1; i<n; i++) {
//             mxl[i] = max(mxl[i-1], height[i]);
//         }
        
//         for(int i=n-2; i>=0; i--) {
//             mxr[i] = max(mxr[i+1], height[i]);
//         }
        
//         for(int i=0; i<n; i++) {
//             water += min(mxl[i], mxr[i]) - height[i];
//         }
        
        //Most Optimal Solution : SC : O(1)
        
        int left = 0, right = n-1, leftMax = 0, rightMax = 0;
        
        while(left < right) {
            if(height[left] <= height[right]) {
                if(leftMax > height[left]) water += (leftMax - height[left]);
                else leftMax = height[left];
                ++left;
            }
            else {
                if(rightMax > height[right]) water += (rightMax - height[right]);
                else rightMax = height[right];
                --right;
            }
        }
        
        
        return water;
        
    }
};