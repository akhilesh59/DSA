class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* tmp = st.top(); st.pop();
        pushAllLeft(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushAllLeft(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */