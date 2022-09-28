class Solution {
#define ll long long
private:
    
    bool RabinKarp(string& pat, string& txt, ll mod) {
        ll n = txt.length(), m = pat.length();
        ll d = 26; // muliplicative factor, because there are 256 characters

        ll i, j;
        ll p = 0; // hash value for pattern
        ll t = 0; // hash valur for the text

        ll h = 1; // value will be used for excluding the leftmost character form the window

        for(i=0; i<m-1; ++i) {
            h = (h*d)%mod;
        }

        // Calculate the hash value of the pattern and first window of text
        for(i=0; i<m; ++i) {
            p = (p*d + pat[i])%mod;
            t = (t*d + txt[i])%mod;
        }

        // cout<<"p = "<<p<<'\n'<<"t = "<<t<<'\n';

        // Now slide the pattern over the text one by one:
        for(i=0; i<=n-m; ++i) {
            if(p == t) {
                for(j=0; j<m; ++j) {
                    if(pat[j] != txt[i+j]) break;
                }
            }

            if(j == m) {
                j=0;
                return true;
            }

            if(i < n-m) {
                t = (( t - txt[i]*h )*d + txt[i+m])%mod;

                if(t<0) t += mod;
            }
        }

        return false;
    }
    
public:
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        
        ll mod = 1e9+7;
        
        string str = a;
        ll cnt = 1;
        
        while(str.length() < b.length()) {
            str += a;
            ++cnt;
        }
        
        // cout<<"a = "<<a<<", b = "<<b<<'\n';
        
        // cout<<"1. str = "<<str<<'\n';
        
        if(RabinKarp(b, str, mod)) return cnt;
        str += a;
        if(RabinKarp(b, str, mod)) return cnt+1;
        
        // cout<<"2. str = "<<str<<'\n';
        
        return -1;
        
    }
};