class Solution {
private:
    bool validate(TreeNode* root, long long l_bound, long long u_bound) {
        if(!root) return true;
        if(root->val <= l_bound || root->val >= u_bound) return false;
        
        return validate(root->left, l_bound, root->val) && validate(root->right, root->val, u_bound);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};