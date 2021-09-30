#include<bits/stdc++.h>
using namespace std;

void solve(string str, unordered_set<string>& dict, string asf) {
    
    if(str.length() == 0) {
        cout<<asf<<"\n";
        return;
    }
    
    for(int i=0; i<str.length(); i++) {
        string left = str.substr(0,i+1);
        if(dict.count(left) > 0) {
            string right = str.substr(i+1); // substr from i+1 till the end
            solve(right, dict, asf + left + ' ');
        }
    }
    
    
}

int main() {
    int n; cin >> n;
    unordered_set<string> dict; // dictioanry of the valid words
    
    while(n--) {
        string tmp; cin >> tmp;
        dict.insert(tmp);
    }
    
    string str; cin >> str;
    
    solve(str, dict, "");
    
    return 0;
}