class Solution {
public:
    
    // idx ko address se pass karna hoga tabhi tree shi se construct hoga and har element k liye unique node banegi.
    
    TreeNode* makeBST(vector<int>& p, int& idx, int u_bound) {
        
        if(idx == p.size() || p[idx] > u_bound) return NULL;
        
        TreeNode* root = new TreeNode(p[idx]);
        idx++;
        root->left = makeBST(p, idx, root->val);
        root->right = makeBST(p, idx, u_bound);
        
        return root;        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return makeBST(preorder, idx, INT_MAX);        
    }
};