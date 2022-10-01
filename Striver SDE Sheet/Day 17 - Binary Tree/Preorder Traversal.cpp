class Solution {    
private: 
    void recur(TreeNode *node, vector<int>& preorder) {
        if(node == NULL) return;
        
        preorder.push_back(node->val);
        recur(node->left, preorder);
        recur(node->right, preorder);
    }
    
    void preorderIterative(TreeNode* root, vector<int>& ans) {
        stack<TreeNode*> st;
        
        while(1) {
            if(root != NULL) {
                ans.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            else {
                if(st.empty()) break;
                
                root = st.top(); st.pop();
                root = root->right;
            }
        }
        
        return;
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> preorder;
        
        // recur(root, preorder);
        preorderIterative(root, preorder);
        
        return preorder;
        
    }
};