#include <bits/stdc++.h> 

void prevSmaller(vector<int>& v, vector<int>& nsl) {
    stack<int> st;
    int n = v.size();
    for(int i=0; i<n; ++i) {
        while(!st.empty() && v[st.top()] >= v[i]) st.pop();
        if(st.empty()) {
            nsl[i] = -1;
        }
        else nsl[i] = st.top();
        st.push(i);
    }    
}

void nextSmaller(vector<int>& v, vector<int>& nsr) {
    stack<int> st;
    int n = v.size();
    for(int i=n-1; i>=0; --i) {
        while(!st.empty() && v[st.top()] >= v[i]) st.pop();
        if(st.empty()) {
            nsr[i] = n;
        }
        else nsr[i] = st.top();
        st.push(i);
    }    
}

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> nsl(n), nsr(n);
    prevSmaller(a, nsl);
    nextSmaller(a, nsr);
    
//     for(auto it: nsl) cout<<it<<' ';
//     cout<<'\n';
    
//     for(auto it: nsr) cout<<it<<' ';
//     cout<<'\n';
    
    vector<int> ans(n, INT_MIN);
    
    for(int i=0; i<n; ++i) {
        int window = nsr[i]-nsl[i]-1;
        // For zero based indexing : window-1
        ans[window-1] = max(ans[window-1], a[i]);
    }
    
//     for(auto it : ans) cout<<it<<' ';
//     cout<<'\n';
    
    for(int i=n-2; i>=0; --i) {
        ans[i] = max(ans[i], ans[i+1]);
    }
    
    return ans;
    
}