vector<int> Solution::prevSmaller(vector<int> &v) {
    int n = v.size();
    vector<int> nsl(n);
    stack<int> st;
    
    for(int i=0; i<n; ++i) {
        while(!st.empty() && st.top() >= v[i]) st.pop();
        if(st.empty()) {
            nsl[i] = -1;
            st.push(v[i]);
        }
        else {
            nsl[i] = st.top();
            st.push(v[i]);
        }
    }
    
    return nsl;
}
