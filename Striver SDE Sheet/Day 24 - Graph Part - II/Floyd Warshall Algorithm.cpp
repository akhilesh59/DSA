/* The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
   Do it in-place. */

class Solution {
private:
const int inf = 1e9;

public:
	void shortest_distance(vector<vector<int>>&mat){
	    int n = mat.size();
	    
	    for(int k=0; k<n; ++k) {
	        for(int i=0; i<n; ++i) {
	            for(int j=0; j<n; ++j) {
	                if(i == j) mat[i][j] = 0;
	                else if(mat[i][j] == -1) mat[i][j] = inf;
	            }
	        }
	    }
	    
	    for(int k=0; k<n; ++k) {
	        for(int i=0; i<n; ++i) {
	            for(int j=0; j<n; ++j) {
	                mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
	            }
	        }
	    }
	    
	    for(int k=0; k<n; ++k) {
	        for(int i=0; i<n; ++i) {
	            for(int j=0; j<n; ++j) {
	                if(mat[i][j] == inf) mat[i][j] = -1;
	            }
	        }
	    }
	    
	    
	}
};