#include<bits/stdc++.h>
using namespace std;

int getMin(string str) {
    stack<char> s;

    for(int i=0; i<str.length(); i++) {
        if(s.empty() || s.top() == ')' || (s.top() == '(' and str[i] == '(')) s.push(str[i]);
        else s.pop();
    }
    
    return s.size();
}

void solve(string str, unordered_set<string>& st, int mra) {
    
    if(mra == 0) {
        int max_rem_now = getMin(str);
        if(max_rem_now == 0) {
            if(st.count(str) == 0) {
                st.insert(str);
                cout<<str<<"\n";
            }
        }
        return;
    }
    
    for(int i=0; i<str.length(); i++) {
        string left = str.substr(0,i);
        string right = str.substr(i+1); // substr from i+1 till the end
        solve(left + right, st, mra-1);
    }
    
    
}

int main() {
    string str; cin >> str;
    
    unordered_set<string> st;

    int mra = getMin(str); // mra -> max removal allowed

    solve(str, st, mra);
    
    return 0;
}