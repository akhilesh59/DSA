/*--------------------------------- O(2n) Space Solution ------------------------------------*/

class MinStack {
    #define ll long long
private:
    stack<pair<ll,ll>> st;
public:
    MinStack() {}
    
    void push(int val) {
        ll mini = INT_MAX;
        if(st.empty()) {
            mini = val;
            st.push({val, mini});
        }
        else {
            mini = min(mini, st.top().second);
            st.push({val, mini});
        }        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        st.top().second;
    }
};

/*--------------------------------- O(n) Space Solution ------------------------------------*/

class MinStack {
    #define ll long long
private:
    stack<ll> st;
    ll mini = 0;
public:
    MinStack() {}

    void push(int val) {
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
            st.pop();
        }
    }

    int top() {
        if(st.top() < mini) {
            return mini;
        }

        return st.top();
    }

    int getMin() {
        return mini;
    }
};