class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0, n = nums.size();
        int low = 0, high = n-1;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            if((mid == 0 || nums[mid] != nums[mid-1]) && (mid == n-1 || nums[mid] != nums[mid+1])) 
                return nums[mid];
            else if(mid%2 == 0 && (mid == n-1 || nums[mid] != nums[mid+1])) 
                high = mid-1;
            else if(mid%2 && (mid == n-1 || nums[mid] == nums[mid+1])) 
                high = mid-1;
            else 
                low = mid+1;
        }
        return -1;
    }
};