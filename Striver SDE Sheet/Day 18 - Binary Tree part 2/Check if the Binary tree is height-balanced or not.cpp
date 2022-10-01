class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return (height_diff(root) != -1);
    }
    
private:
    int height_diff(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lh = height_diff(root->left);
        if(lh == -1) return -1;
        
        int rh = height_diff(root->right);
        if(rh == -1) return -1;
        
        if(abs(lh-rh) > 1) return -1;
        
        return (1+max(rh,lh));
    }
};