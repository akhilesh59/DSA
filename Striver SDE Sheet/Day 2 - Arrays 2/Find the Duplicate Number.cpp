class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int slow = v[0], fast = v[0];
        
        do {
            fast = v[v[fast]];
            slow = v[slow];
        } while(slow != fast);
        
        fast = v[0];
        while(slow != fast) {
            slow = v[slow];
            fast = v[fast];
        }
        return fast;
        
    }
};