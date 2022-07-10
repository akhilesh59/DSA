class Solution {
public:
    void nextPermutation(vector<int>& v) {
        // Direct Answer:
        // next_permutation(nums.begin(), nums.end());
        
        // Correct method:
        
        // 1. Find the rightmost peak:
        int n = v.size();
        int idx = -1;
        for(int i=1; i<n; i++) {
            if(v[i] > v[i-1]) idx = i;
        }
        
        // 2. Check for descending order:
        if(idx == -1) {
            reverse(v.begin(), v.end());
            return;
        }
        
        // Find the element to be swapped which is on the right of the peak and whose value is in between the peak and the element before the peak.
        int final_idx = idx; // correct index which is to be swapped with the element prev to peak
        for(int i=idx+1; i<n; i++) {
            if(v[i]>v[idx-1] and v[i]<=v[idx])  final_idx = i;
        }
        
        // now swap:
        swap(v[final_idx], v[idx-1]);
        
        // now rev the array starting from the index which is swapped
        reverse(v.begin()+idx, v.end());
        // sort(v.begin()+idx, v.end());
        
    }
};