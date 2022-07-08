class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // Approach 1 : Using Hashmap
        
        /*unordered_map<int,int> mp;
        for(auto i : nums) mp[i]++;
        int maxi = INT_MIN, ans = -1;
        for(auto it : mp) if(maxi < it.second) maxi = it.second, ans = it.first;
        return ans;*/
        
        // Approach 2 : Using Moore Voting Algorithm , T -> O(n) and S -> (1)
        
        int val = nums[0], cnt = 1;
        
        for(int i=1; i<nums.size(); i++) {
            if(val == nums[i]) cnt++;
            else cnt--;
            
            if(cnt == 0) val = nums[i], cnt = 1;
        }
        return val;
    }
};