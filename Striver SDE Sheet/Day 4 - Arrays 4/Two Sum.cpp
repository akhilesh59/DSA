class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        unordered_map<int,int> mp;
                
        for(int i=0; i<v.size(); i++) {
            int req = t-v[i];
            if(mp.find(req) != mp.end()) return {i, mp[req]};
            mp[v[i]] = i;
        }
        
        return {};
    }
};