class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";
        
        string s = "11";
        
        for(int i=3; i<=n; ++i) {
            int cnt = 1;
            string tmp = "";
            for(int j=1; j<s.length(); ++j) {
                if(s[j] != s[j-1]) {
                    tmp += (to_string(cnt) + s[j-1]);
                    cnt = 1;
                }
                else ++cnt;
                
                if(j == s.length()-1) {
                     tmp += (to_string(cnt) + s[j]);
                }
            }
            s = tmp;            
        }
        
        return s;
    }
};