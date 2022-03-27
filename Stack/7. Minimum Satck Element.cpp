class MinStack {
    #define ll long long
private:
    stack<ll> st;
    // stack<int> tmp;
    ll mini = 0, sum = 0;
public:
    MinStack() {}
    
    void push(int val) {
        // st.push(val);
        // if(tmp.empty() || tmp.top() >= val) tmp.push(val);
        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else if(mini > val) {
            ll x = 2LL*val - mini;
            mini = val;
            st.push(x);
        }        
        else st.push(val);
    }
    
    void pop() {
        if(!st.empty()) {
            if(st.top() < mini) {
                mini = 2*mini - st.top();
            }
            // int x = st.top(); st.pop(); 
            // if(x == tmp.top()) tmp.pop();
            st.pop();
        }
    }
    
    int top() {
        // return st.top();
        if(st.top() < mini) {
            return mini;
        }
        
        return st.top();
    }
    
    int getMin() {
        // return tmp.top();
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */