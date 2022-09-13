class MyStack {
private:
    deque<int> dq;
public:
    MyStack() {
        dq.clear();
    }
    
    void push(int x) {
        dq.push_front(x);
    }
    
    int pop() {
        int x = dq.front();
        dq.pop_front();
        return x;
    }
    
    int top() {
        return dq.front();
    }
    
    bool empty() {
        return (dq.size()>0 ? 0 : 1);
    }
};

// ------------------------------------- Optimal Solution --------------------------------//

class MyStack {
queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int sz = q.size();
        q.push(x);
        
        for(int i=0; i<sz; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
