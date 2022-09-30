class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!right.empty() && right.top() < num) {
            right.push(num);
        }
        else left.push(num);
        
        int ls = left.size(), rs = right.size();
        if(ls > rs && ls-rs > 1) {
            int x = left.top(); left.pop();
            right.push(x);
        }
        else if(rs > ls && rs-ls > 1) {
            int x = right.top(); right.pop();
            left.push(x);
        }
        
    }
    
    double findMedian() {
        double ans = 0;
        int ls = left.size(), rs = right.size();
        
        if(ls == rs) {
            double n1 = left.top(), n2 = right.top();
            ans = (n1+n2)/2;
        }
        else ans = ls > rs ? left.top() : right.top();
        
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */