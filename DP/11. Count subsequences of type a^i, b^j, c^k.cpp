class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        long long mod = 1e9+7;
        int a=0;
        int ab=0;
        int abc=0;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'a') {
                a = (2*a)%mod + 1;
            }
            else if(s[i] == 'b') {
                ab = ((2*ab)%mod + a)%mod;
            }
            else {
                abc = ((2*abc)%mod + ab)%mod;
            }
        }
        
        return abc;
    }
};