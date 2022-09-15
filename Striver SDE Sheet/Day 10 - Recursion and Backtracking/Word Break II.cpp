#include<bits/stdc++.h>
vector<string> ans;
void recur(string rem, unordered_set<string>& st, string ssf) {
    if(rem.length() == 0) {
        ans.push_back(ssf);
        return;
    }
    
    for(int i=0; i<rem.length(); ++i) {
        string left = rem.substr(0,i+1);
        if(st.count(left) > 0) {
            string right = rem.substr(i+1);
            string tmp = ssf;
            if(ssf.length()) tmp += " ";
            tmp += left;
            recur(right, st, tmp);
        }
    }
    
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    ans.clear();
    unordered_set<string> st;
    for(string it : dictionary) st.insert(it);
    
    recur(s, st, "");
    
    return ans;

}