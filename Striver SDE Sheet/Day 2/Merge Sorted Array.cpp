class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        if(n == 0) return;
//         vector<int> tmp(m+n);
//         int i=0,j=0,k=0;
//         while(i < m && j < n) {
//             if(v1[i] <= v2[j]) {
//                 tmp[k++] = v1[i];
//                 i++;
//             }
//             else {
//                 tmp[k++] = v2[j];
//                 j++;
//             }
//         }
        
//         while(i < m) tmp[k++] = v1[i++];
//         while(j < n) tmp[k++] = v2[j++];
        
//         v1 = tmp;
        
        // Without using Extra Space:
        
        int i=0, j=0;
        while(i<m) {
            if(v1[i] > v2[0]) swap(v1[i], v2[0]);
            
            int f = v2[0];
            // insert it in its correct position in v2 using insertion sort
            for(j=1; j<n && f>=v2[j]; j++) v2[j-1] = v2[j];
            
            v2[j-1] = f;
            
            i++;            
        }
        
        i = m, j = 0;
        while(j < n) {
            v1[i++] = v2[j++];
        }

    }
};