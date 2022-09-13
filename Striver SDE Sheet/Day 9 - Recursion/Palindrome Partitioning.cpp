class Solution {
private:
    static bool isPal(string &s, int low, int high) {
        while(low < high) {
            if(s[low++] != s[high--]) return false;
        }
        return true;
    }
    
    void recur(vector<vector<string>>& ans, string& s, vector<string>& tmp, int idx) {
        if(idx == s.length()) {
            ans.push_back(tmp);
            return;
        }
        
        for(int i=idx; i<s.length(); ++i) {
            if(isPal(s, idx, i)) {
                string ss = s.substr(idx, i-idx+1);
                tmp.push_back(ss);
                recur(ans, s, tmp, i+1);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        
        recur(ans, s, tmp, 0);
        return ans;
    }
};