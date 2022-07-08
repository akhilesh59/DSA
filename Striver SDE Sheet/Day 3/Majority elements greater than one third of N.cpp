class Solution {
private:
    bool chk_cnt(vector<int>& nums, int num) {
        int cnt = 0;
        for(auto it : nums) if(it == num) cnt++;
        return cnt > (nums.size()/3);
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=INT_MIN, num2=INT_MIN, cnt1 = 0, cnt2 = 0;
        for(auto it : nums) {
            if(it == num1) cnt1++;
            else if(it == num2) cnt2++;
            else if(cnt1 == 0) num1 = it, cnt1 = 1;
            else if(cnt2 == 0) num2 = it, cnt2 = 1;
            else --cnt1, --cnt2;
        }
        vector<int> ans;
        if(chk_cnt(nums, num1)) ans.push_back(num1);
        if(chk_cnt(nums, num2)) ans.push_back(num2);
        
        return ans;
    }
};