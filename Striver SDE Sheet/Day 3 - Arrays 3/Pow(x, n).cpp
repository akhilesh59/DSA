class Solution {
private: 
    double bin_pow(double num, int po) {
        if(po == 0) return (double)1.0;
        else if(po == 1) return num;
        
        double tmp = bin_pow(num, po/2);
        double res = tmp*tmp;
        
        if(po&1) res *= num;
        
        return res;
    }
public:
    double myPow(double x, int n) {
        double num = abs(x), po = abs(n);
        double ans = bin_pow(num, po);
        if(n < 0) ans = (double)1/ans;
        if(x < 0 && n%2) ans = -ans;
        
        return ans;
    }
};