class Solution
{
    private:
    
    static bool cmp(pair<int,int>& a, pair<int,int>& b) {
        return a.second < b.second;
    }
    
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int s[], int e[], int n)
    {
        vector<pair<int,int>> vp;
        for(int i=0; i<n; ++i) {
            vp.push_back({s[i],e[i]});
        }
        
        sort(vp.begin(), vp.end(), cmp);
        
        int cnt = 1, x = vp[0].second;
        
        for(int i=1; i<n; ++i) {
            if(vp[i].first <= x) continue;
            else {
                ++cnt;
                x = vp[i].second;
            }
        }
        return cnt;
    }
};