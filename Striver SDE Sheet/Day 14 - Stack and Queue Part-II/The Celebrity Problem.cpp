#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
     stack<int> st;
    for(int i=0; i<n; ++i) st.push(i);
    
    while(st.size()>1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        int res = knows(a,b) ? b : a;
        st.push(res);
    }
    
    int celebrity = st.top();
    
    for(int i=0; i<n; ++i) {
        if(i == celebrity) continue;
        else if(knows(celebrity, i) || !knows(i, celebrity)) return -1;
    }
    
    return celebrity;
}