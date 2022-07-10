class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
        Intuition: We can clearly observe that, each time we are taking an exactly m+n-2 number         of steps to reach the end.
        -> So we can conclude that, we need n-1 no. of rightward direction and m-1 no. of downward direction to reach the endpoint.
        
        -> Hence using Combinatorics we can calculate the total Number of Paths as:
            Total Paths = (m+n-2)C(m-1) or (m+n-2)C(n-1) {any one of them will give answer}
        */
        
        long long N = m+n-2;
        long long r = m-1;    // N^Cr
        long long ans = 1;
        
        for(long long i=1; i<=r; ++i) {
            ans = ans*(N-r+i)/i;
        }
        
        return ans;
    }
};