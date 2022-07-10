class Solution {
private:
    int merge(vector<int>& arr, int low, int mid, int high) {
        int cnt = 0;
        int j = mid+1;
        
        for(int i=low; i<=mid; ++i) {
            while(j <= high && arr[i] > 2LL*arr[j]) j++;
            
            cnt += j - (mid+1);
        }
        
        // Now merge both the left part and the right part:
        vector<int> tmp;
        int left = low, right = mid+1;
        
        while(left <= mid && right <= high) {
            if(arr[left] < arr[right]) {
                tmp.push_back(arr[left]);
                ++left;
            }
            else {
                tmp.push_back(arr[right]);
                ++right;
            }
        }
        
        while(left <= mid) tmp.push_back(arr[left++]);
        while(right <= high) tmp.push_back(arr[right++]);
        
        for(int i=low; i<=high; ++i) {
            arr[i] = tmp[i-low];
        }
        
        return cnt;
    }
    
    int merge_sort(vector<int>& arr, int low, int high) {
        if(low >= high) return 0;
        int mid = low + (high-low)/2;
        
        int cnt = merge_sort(arr, low, mid);
        cnt += merge_sort(arr, mid+1, high);
        
        cnt += merge(arr, low, mid, high);
        
        return cnt;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        int ans = merge_sort(nums, 0, nums.size()-1);
        return ans;
    }
};