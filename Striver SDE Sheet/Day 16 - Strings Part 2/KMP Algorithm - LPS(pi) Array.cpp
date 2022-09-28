#include <bits/stdc++.h>
using namespace std;

void compute_LPS(vector<int>& lps, string pat) {
    int n = pat.length();
    int i=1;
    int len = 0; // length of the previous longest prefix suffix
    lps[0] = 0; // the first character of the pattern will be the first ever prefix itself
    
    
    while(i<n) {
        if(pat[len] == pat[i]) {
            ++len;
            lps[i] = len;
            ++i;
        }
        else {
            if(len != 0) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                ++i;
            }
        }
    }
    
}

void KMP(string& txt, string& pat) {
    int n = txt.length();
    int m = pat.length();
    
    vector<int> lps(m);
    
    compute_LPS(lps, pat);
    
    int i = 0; // index for txt
    int j = 0; // index for pat
    
    while((n-i) >= (m-j)) { // to make sure that remaining pattern is less than or equal to remaing text
        if(txt[i] == pat[j]) {
            ++i;
            ++j;
        }
        
        if(j == m) {
            cout<<"Found pattern at index : "<<i-j<<'\n';
            j = lps[j-1];
        }
        
        else if(i < n && txt[i] != pat[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
        
    }
    
    return;
}

int main() {
    string text; cin >> text;
    string pattern; cin >> pattern;
    
    KMP(text, pattern);
    
    
    return 0;
}