class Solution {
public:
    bool isValid(string s) {
        int n = s.length()-1;
        
        if(s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
        if(s[n] == '(' || s[n] == '{' || s[n] == '[') return false;
        
        stack<char> st;
        
        for(auto ch : s) {
            if(!st.empty()) {
                char x = st.top();
                if(x == '(' && ch == ')') st.pop();
                else if(x == '{' && ch == '}') st.pop();
                else if(x == '[' && ch == ']') st.pop();
                else st.push(ch);
            }            
            else st.push(ch);
        }
        
        return st.empty();
    }
};