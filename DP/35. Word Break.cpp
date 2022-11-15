/*
// 1. Recursion:
class Solution
{
private:
    unordered_map<string,bool> mp;
    
    bool recur(string s) {
        if(s == "") return true;
        int n = s.length();
        
        string tmp = "";
        
        for(int i=0; i<n; ++i) {
            tmp += s[i];
            if(mp.find(tmp) != mp.end() && recur(s.substr(i+1))) {
                return true;
            }
        }
        return false;
    }
public:
    int wordBreak(string A, vector<string> &B) {
        for(string s : B) mp[s] = 1;
        return recur(A);
    }
};
*/

/*
// 2. Memoization:
class Solution
{
private:
    unordered_map<string,bool> mp;
    vector<int> dp;
    
    bool recur(string s, int idx) {
        if(s == "") return true;
        
        if(dp[idx] != -1) return dp[idx];
        
        for(int i=idx; i>=0; --i) {
           string tmp = s.substr(i);
            if(mp.find(tmp) != mp.end() && recur(s.substr(0,i), i-1)) {
                return true;
            }
        }
        return dp[idx] = false;
    }
public:
    int wordBreak(string A, vector<string> &B) {
        dp = vector<int>(A.length()+1,-1);
        for(string s : B) mp[s] = 1;
        return recur(A, A.length()-1);
    }
};
*/

// 3. Tabulation:
class Solution
{
public:
    int wordBreak(string s, vector<string> &B) {
        unordered_map<string,bool> mp;
        int n = s.length();
        
        vector<int> dp(n+1,0);
        for(string str : B) mp[str] = 1;
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<=i; ++j) {
                string tmp = s.substr(j, i-j+1);
                if(mp.find(tmp) != mp.end()) {
                    if(j > 0) dp[i] |= dp[j-1];
                    else dp[i] |= 1;
                }
            }
        }
        
        // for(int i=0; i<n; ++i) cout<<dp[i]<<' ';
        // cout<<'\n';
        
        
        return dp[n-1];
    }
};