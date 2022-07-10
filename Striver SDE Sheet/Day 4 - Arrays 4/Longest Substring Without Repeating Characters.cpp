class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, l=0, r=0;
        map<char,int> mp;
        while(r < s.size()) {
            if(mp[s[r]] == 0) {
                ans = max(ans, (int)(r-l+1));
                mp[s[r]]++;
                r++;
            }
            else mp[s[l]]--, l++;
        }
        
        return ans;
        
    }
};