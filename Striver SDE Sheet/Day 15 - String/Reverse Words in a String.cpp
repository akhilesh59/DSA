class Solution {
public:
    string reverseWords(string s) {
        string ans = "", tmp = "";
        int n = s.length(), i = 0;
        
        while(i < n) {
            if(s[i] != ' ') tmp += s[i];
            else if(tmp != "") {
                if(ans == "") ans = tmp;
                else ans = tmp + " " + ans;
                tmp = "";
            }
            ++i;
        }
        if(tmp != "") {
            if(ans == "") ans = tmp;
            else ans = tmp + " " + ans;
        }
        return ans;
    }
};