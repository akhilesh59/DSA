class Solution {
private:
    void dfs(TreeNode *node, vector<int>& postorder) {
        if(node == NULL) return;

        dfs(node->left, postorder);
        dfs(node->right, postorder);
        postorder.push_back(node->val);
    }
    
    void postorderIterative(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        stack<TreeNode*> st1, st2;
        
        st1.push(root);
        
        while(!st1.empty()) {
            TreeNode *curr = st1.top(); st1.pop();
            st2.push(curr);
            
            if(curr->left) st1.push(curr->left);
            if(curr->right) st1.push(curr->right);
        }
        
        while(!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return;
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> postorder;
        
        // dfs(root, postorder);
        postorderIterative(root, postorder);
        
        return postorder;
        
    }
};