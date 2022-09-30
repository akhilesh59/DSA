#include<queue>

#define ppii pair<int, pair<int,int>>
#define F first
#define S second

vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    vector<int> ans;
    priority_queue<ppii, vector<ppii>, greater<ppii>> pq;
    
    for(int i=0; i<arr.size(); ++i) {
        int num = arr[i][0]; // Taking the 1st element of every sorted arr
        int idx = 0; // index of the element in its array
        int array_idx = i; // index of the array, to which the element belongs
        ppii p = {num, {idx, array_idx}};
        pq.push(p);
    }
    
    while(!pq.empty()) {
        ppii p = pq.top(); pq.pop();
        
        int num = p.F; 
        int idx = p.S.F; 
        int array_idx = p.S.S;
        
        ans.push_back(num);
        
        if(idx+1 < arr[array_idx].size()) {
            int next = arr[array_idx][idx+1];
            ppii p = {next, {idx+1, array_idx}};
            pq.push(p);
        }
        
    }
    
    return ans;
}
