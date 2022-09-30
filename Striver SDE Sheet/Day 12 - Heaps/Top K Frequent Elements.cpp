class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto it : nums) mp[it]++;
        priority_queue<pair<int,int>> pq;
        
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }
        
        while(k--) {
            auto it = pq.top(); pq.pop();
            ans.push_back(it.second);
        }
        
        return ans;
    }
};