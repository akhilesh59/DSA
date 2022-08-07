class Solution 
{
private:
    static bool cmp(Job& a, Job& b) {
        return a.profit > b.profit;
    }
    
public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, cmp);
        int cnt = 0, pro = 0, maxi = INT_MIN;
        for(int i=0; i<n; ++i) maxi = max(maxi, arr[i].dead);
        vector<int> vacant(maxi+1,0);
        
        for(int i=0; i<n; ++i) {
            for(int j=arr[i].dead; j>0; --j) {
                if(!vacant[j]) {
                    vacant[j] = 1;
                    ++cnt;
                    pro += arr[i].profit;
                    break;
                }
            }
        }
        
        return {cnt, pro};
    } 
};