class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int,int>> st;
       vector<int> ans;
       
       for(int i=0; i<n; i++) {
           int span = 1;    // For itself
           while(!st.empty() && st.top().first <= price[i]) {
               span += st.top().second;
               st.pop();
           }
           
           ans.push_back(span);
           st.push({price[i], span});
       }
       
       return ans;
    }
};