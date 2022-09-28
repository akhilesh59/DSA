class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for(char ch : s) mp[ch]++;
        for(char ch : t) {
            if(mp.find(ch) != mp.end()) mp[ch]--;
            else return false;
        }
        
        for(auto it : mp) 
            if(it.second != 0) 
                return 0;
        
        return 1;
    }
};