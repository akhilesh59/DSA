class Solution {
private:    
    bool recur(TreeNode* left, TreeNode* right) {
        if(left == NULL || right == NULL) {
            return left == right;
        }
        
        if(left->val != right->val) return false;
        
        return recur(left->left, right->right) && recur(left->right, right->left);
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        return (root == NULL) || recur(root->left, root->right);
    }
};