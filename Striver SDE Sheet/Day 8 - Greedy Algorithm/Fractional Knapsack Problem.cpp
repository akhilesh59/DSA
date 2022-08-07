class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> vp;
        for(int i=0; i<n; ++i) {
            double x = (double)arr[i].value/(double)arr[i].weight;
            vp.push_back({x,i});
        }
        
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        
        double profit = 0;
        int curr = W;
        for(int i=0; i<n; ++i) {
            if(curr <= 0) break;
            int idx = vp[i].second;
            if(curr < arr[idx].weight) {
                double x = vp[i].first*curr;
                profit += x;
                curr = 0;
            }
            else {
                profit += arr[idx].value;
                curr -= arr[idx].weight;
            }
        }
        
        return profit;
    }
        
};