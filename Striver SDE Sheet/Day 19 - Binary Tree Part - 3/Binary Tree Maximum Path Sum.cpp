class Solution {
private:
    int recur(TreeNode* root, int& ans) {
        if(!root) return 0;
        
        int left = max(0, recur(root->left, ans));
        int right = max(0, recur(root->right, ans));
        
        ans = max(ans, root->val+left+right);

        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        if(!root) return ans;
        
        recur(root, ans);
        
        return ans;
    }
};