class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        
        unordered_set<int> st;        
        for(auto it : nums) st.insert(it);
        int ans = 1;
        
        for(auto it : st) {
            if(!st.count(it-1)) {
                int len = 1;
                int curr = it;
                
                while(st.count(++curr)) ++len;
                
                ans = max(ans, len);
            }
        }
        
        /*
        if(!st.count(it-1)) -> means, only the value 1 is valid for the loop because all the other values of the subsequence will have their -1 values except the first one. And here a lot of our iterations will be saved. And that is O(n).

        */
        
        return ans;
    }
};