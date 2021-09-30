#include<bits/stdc++.h>             // Not in sequential manner
using namespace std;

void printAns(vector<char>& vc) {
    for(auto i : vc) cout<<i;
    cout<<"\n";
}

void solve(string s, int idx, vector<char>& boxes, unordered_map<char,int>& ump) {
    if(idx == s.length()) {
        printAns(boxes);
        return;
    }

    char ch = s[idx];
    int last_occurence = ump[ch];
    

    for(int i = last_occurence+1; i<boxes.size(); i++) {
        if(boxes[i] == '0') {
            boxes[i] = ch;
            ump[ch] = i;
            solve(s,idx+1,boxes,ump);
            ump[ch] = last_occurence;
            boxes[i] = '0';
        }
    }
}

int main() {
    string s;
    cin >> s;

    unordered_map<char,int> last_occurence;
    for(int i=0; i<s.length(); i++) {
        last_occurence[s[i]] = -1;
    }

    int len = s.length();

    vector<char> boxes(len,'0');

    solve(s,0,boxes,last_occurence);

    return 0;
}