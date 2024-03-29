class Solution {
private:
    int height(TreeNode* node, int &diameter) {
        if(!node) return 0;
        
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        
        diameter = max(diameter, lh+rh);
        
        return (1 + max(lh,rh));
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        
        int diameter = 0;
        height(root, diameter);
        
        return diameter;
    }
};