class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n = v.size();
        vector<int> nge(n, -1);
        stack<int> st;
        
        for(int i = 2*n - 1; i>=0; --i) {
            while(!st.empty() && st.top() <= v[i%n]) st.pop();
            
            if(i < n) {
                if(!st.empty()) nge[i%n] = st.top();
            }
            
            st.push(v[i%n]);
        }
        
        return nge;
    }
};