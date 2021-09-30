#include<bits/stdc++.h>     // GFG
using namespace std;

class Solution{
public:

    vector<vector<int>> ans;
    
bool safetyCheck(int n, int r, int c, vector<vector<int>>& v) {
    // for vertical cancellation:
    for(int row = r; row>=0; row--) {
        if(v[row][c] == 1) return false;
    }
    
    // Checking the left diagonal
    int row = r, col = c;
    while(row >= 0 && col >= 0) {
        if(v[row][col] == 1) return false;
        row--;
        col--;
    }
    
    // Checking the right diagonal
    row = r, col = c;
    while(row >= 0 && col < n) {
        if(v[row][col] == 1) return false;
        row--;
        col++;
    }
    return true;
}

    bool solve(int n, vector<int>& op, int r, vector<vector<int>>& v) {
        if(r == n) {
            ans.push_back(op);
            return false;
        }
        
       
        
        for(int i=0; i<n; i++) {
            if(safetyCheck(n,r,i,v)) {
                v[r][i] = 1;
                op.push_back(i+1);
                
                solve(n,op,r+1,v);
                
                v[r][i] = 0;
                op.pop_back();
                
            }
        }
        
        return false;
    }

    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>> v(n,vector<int>(n,0));
        
        vector<int> op;
        
        solve(n,op,0,v);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};
