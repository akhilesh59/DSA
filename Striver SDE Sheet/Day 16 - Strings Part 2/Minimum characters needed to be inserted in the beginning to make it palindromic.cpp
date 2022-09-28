#include<bits/stdc++.h>

int minCharsforPalindrome(string& A) {
    // Going to use KMP Algorithm's LPS array to compute the longest prefix which is palindrome 
    // in O(n) time:
    
    string rev = A;
    reverse(rev.begin(), rev.end());
    
    string s = A + "$" + rev;
    
    int n = s.length();
    vector<int> lps(n);
    lps[0] = 0;
    int j = 0, i = 1;
    
    while(i < n) {
        if(s[j] == s[i]) {
            lps[i] = j+1;
            ++j;
            ++i;
        }
        else {
            if(j != 0) {
                j = lps[j-1];
            }
            else {
                lps[i] = 0;
                ++i;
            }
        }
    }
    
    return (A.length()-lps.back());
    
}
