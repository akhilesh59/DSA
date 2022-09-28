class Solution {
private:
    
    vector<int> getZarr(string& pat, string& txt) {
        string s = pat + "$" + txt;
        int n = s.length();
        int L=0, R=0;
        int k;
        vector<int> Z(n,0);

        for(int i=1; i<n; ++i) {
            if(i>R) {
                L=R=i;

                while(R<n && s[R-L] == s[R]) ++R;

                Z[i] = (R-L);
                --R;
            }
            else {
                k = i-L;

                if((i + Z[k] - 1) < R) {
                    Z[i] = Z[k];
                }
                else {
                    L = i;
                    while(R<n && s[R-L] == s[R]) ++R;

                    Z[i] = (R-L);
                    --R;
                }
            }
        }

        return Z;

    }
    
public:
    int strStr(string txt, string pat) {
        vector<int> Z_arr = getZarr(pat, txt);
    
        for(int i=0; i<Z_arr.size(); ++i) {
            if(Z_arr[i] == pat.length()) {
                return (i-pat.length()-1);
            }
        }
        
        return -1;
    }
};