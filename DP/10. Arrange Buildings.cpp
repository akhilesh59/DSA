class Solution{
	public:
	int TotalWays(int n)
	{
	    long long mod = 1e9+7;
	  
	    
	    long long prev_b = 1;
	    long long prev_s = 1;
	    long long curr_b = 1;
	    long long curr_s = 1;
	    
	    for(long long i=2; i<=n; i++) {
	        curr_b = prev_s % mod;
	        curr_s = (prev_b%mod + prev_s%mod)%mod;
	        prev_b = curr_b;
	        prev_s = curr_s;
	    }
	    
	    long long ans = (curr_b + curr_s)%mod;
	    
	    return (ans*ans)%mod; // Sqaure is done because road k dono side alag alag
	    // combinations bana sakte hai ek taraf k ek combination k respect me.
	}
};