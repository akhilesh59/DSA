class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum=0, max_sum=INT_MIN;
        for(auto it : nums) {
            curr_sum += it;
            max_sum = max(max_sum, curr_sum);
            if(curr_sum < 0) curr_sum = 0;
        }
        return max_sum;
    }
};