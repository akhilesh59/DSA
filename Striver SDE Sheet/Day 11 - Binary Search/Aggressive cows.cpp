#include<bits/stdc++.h>
using namespace std;

#define int long long

bool chk(vector<int>& v, int dis, int c) {
    int cnt = 1;
    int n = v.size();
    int last_picked = v[0];

    for(int i=1; i<n; ++i) {
        if(v[i] - last_picked >= dis) {
            last_picked = v[i];
            ++cnt;
        }
    }

    return cnt >= c;
}

void solve() {
    int n,c; cin >> n >> c;
    vector<int> v(n);
    for(auto &it : v) cin >> it;

    sort(v.begin(), v.end());

    int low = 1, high = v[n-1];
    int ans = -1;

    while(low <= high) {
        int mid = low + (high-low)/2;

        if(chk(v, mid, c)) {
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }

    cout<<ans<<'\n';
}

int32_t main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}