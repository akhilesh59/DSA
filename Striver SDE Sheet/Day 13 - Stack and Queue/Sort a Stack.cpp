void insert(stack<int>& st, int tmp) {
    if(st.empty() || st.top() <= tmp) {
        st.push(tmp);
        return;
    }
    
    int val = st.top(); st.pop();
    insert(st, tmp);
    st.push(val);
    return;
    
}

void sortStack(stack<int> &st)
{
	if(st.empty()) return;
    int tmp = st.top(); st.pop();
    
    sortStack(st);
    insert(st, tmp);
    return;
}
