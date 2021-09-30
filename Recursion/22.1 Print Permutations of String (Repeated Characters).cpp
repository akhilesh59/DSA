#include<bits/stdc++.h>     // Permutations will be in sequential manner
using namespace std;

void solve(string s, string& op, map<char,int>& freq) {
    if(op.length() == s.length()) {
        cout<<op<<"\n";
        return;
    }

    for(auto ch = freq.begin(); ch != freq.end(); ch++) {
        if(ch->second > 0) {
            ch->second -= 1;
            op.push_back(ch->first);
            solve(s,op,freq);
            op.pop_back();
            ch->second += 1;
        }
    }

    // We can use for each loop in any map in the given manner : 
    /* 
        for(auto& ch : freq) {
            if(ch.second > 0) {
                ch.second -= 1;
                op.push_back(ch.first);
                solve(s,op,freq);
                op.pop_back();
                ch.second += 1;
            }
        }
    */
}

int main() {
    string s;
    cin >> s;

    map<char,int> frequency;
    for(int i=0; i<s.length(); i++) {
        frequency[s[i]] += 1;
    }

    string op = "";

    solve(s,op,frequency);

    return 0;
}