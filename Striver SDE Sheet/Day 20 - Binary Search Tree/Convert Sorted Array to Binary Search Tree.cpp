class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return construct(nums, 0, nums.size()-1);
    }
private:
    TreeNode* construct(vector<int>& v, int left, int right) {
        if(left > right) return NULL;
        
        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(v[mid]);
        
        root->left = construct(v, left, mid-1);
        root->right = construct(v, mid+1, right);
        
        return root;
    }
};