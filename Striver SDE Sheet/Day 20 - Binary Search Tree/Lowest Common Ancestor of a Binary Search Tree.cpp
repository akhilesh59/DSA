class Solution {
#define LCA lowestCommonAncestor
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root == p || root == q) return root;
        
        // Iterative :
        
        while(root) {
            if(p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            else if(p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            else return root;
        }
        
        // Recursive:
        
        // if(p->val < root->val && q->val < root->val) {
        //     return LCA(root->left, p, q);
        // }
        // else if(p->val > root->val && q->val > root->val) {
        //     return LCA(root->right, p, q);
        // }
        // return root;
        
        return NULL;
    }
};