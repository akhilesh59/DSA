// Approach 1 : TC = O(nlogn) | SC = O(1)

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int i=0,j=0,cnt=0,ans=INT_MIN;
    	
    	while(i<n && j<n) {
    	    if(arr[i] <= dep[j]) ++cnt, ++i;
    	    else --cnt, ++j;
    	    ans = max(ans, cnt);
    	}
    	
    	return ans;
    }
};

// Approach 1 : TC = O(n) | SC = O(n)

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<int> fq1(2400, 0), fq2(2400,0);
    	
    	for(int i=0; i<n; ++i) {
    	    ++fq1[arr[i]];
    	    --fq2[dep[i]];
    	}
    	int maxi = INT_MIN, curr = 0;
    	for(int i=0; i<2400; ++i) {
    	    curr += fq1[i];
    	    maxi = max(maxi, curr);
    	    curr += fq2[i];
    	}
    	
    	return maxi;
    }
};