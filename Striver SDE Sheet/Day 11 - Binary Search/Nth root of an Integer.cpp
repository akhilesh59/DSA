#include <bits/stdc++.h> 
double multiply(double num, int n) {
    double res = 1.0;
    for(int i=0; i<n; ++i) {
        res *= num;
    }
    return res;
}
double findNthRootOfM(int n, int m) {
	double low = 1, high = m;
    double precision = 1e-7;
    while((high-low) > precision) {
        double mid = low + ((high-low)/2.0);
        if(multiply(mid, n) < m) {
            low = mid;
        }
        else high = mid;
    }
    
    return low;
}