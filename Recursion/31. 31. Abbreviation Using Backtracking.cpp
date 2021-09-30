#include<bits/stdc++.h>
using namespace std;

void solve(string& str, int count, string asf, int idx) {
    
    if(idx == str.length()) {
        if(count == 0) cout<<asf<<"\n";
        else cout<<asf<<count<<"\n";
        return;
    }
    
    
    if(count > 0) {
        // Call for Yes, but we will stick a number with the answer
        solve(str, 0, asf + to_string(count) + str[idx], idx + 1); 
    }
    else {
        // Call for Yes, but count is 0, so we need not to stick a number with the answer
        solve(str, 0, asf + str[idx], idx + 1);
    }
    
    // Call for No
    solve(str, count + 1, asf, idx + 1);
    
}

int main() {
    string str; cin >> str;
    
    solve(str, 0, "", 0);
    
    return 0;
}