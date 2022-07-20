class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int i=0, j=1, n = v.size();
        if(n == 1) return 1;
        
        while(i<n && j<n) {
            if(v[i] == v[j]) {
                while(j<n && v[i] == v[j]) ++j;
                if(j<n) v[i+1] = v[j];
                else break;
            }
            ++i;
        }
        
        return ++i;
    }
};