class Solution {
public:
    int myAtoi(string s) {
        int mul = 1, cnt = 0;
        long long res = 0;
        bool space = 0, sign = 0, num = 0;
        
        for(char ch : s) {
            if(num && (ch < '0' || ch > '9')) break;
            if(ch == ' ') {
                if(space == 1) break;
                continue;
            }
            else if(ch == '+' || ch == '-') {
                if(sign) break;
                mul = (ch == '-') ? -1 : 1;
                sign = 1;
            }
            else if(ch == '.') break;
            else if(ch >= '0' && ch <= '9' && cnt < 12) {
                res = (res*10) + (ch-'0');
                num = 1;
                if(res > 0) ++cnt;
            }       
            else break;
            if(ch != ' ') space = 1;
            
        }
        
        res *= mul;
        
        if(res <= -2147483648)return -2147483648;
        if(res >= 2147483647)return 2147483647;
        return res;
    }
};