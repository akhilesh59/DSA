class Solution {
public:
    int compareVersion(string s1, string s2) {
        int i=0, j=0, n1 = s1.length(), n2 = s2.length();
        
        while(i<n1 || j<n2) {
            int res1 = 0, res2 = 0;
            
            while(i < n1 && s1[i] != '.') {
                res1 = res1*10 + (s1[i]-'0');
                ++i;
            }
            
            while(j < n2 && s2[j] != '.') {
                res2 = res2*10 + (s2[j]-'0');
                ++j;
            }
            
            if(res1 > res2) return 1;
            else if(res2 > res1) return -1;
            
            ++i, ++j;
        }
        
        return 0;
    }
};