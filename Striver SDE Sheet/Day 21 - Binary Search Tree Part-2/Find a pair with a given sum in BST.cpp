class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse;
    
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmp = st.top(); st.pop();
        if(reverse == false) pushAll(tmp->right);
        else pushAll(tmp->left);
        return tmp->val;
    }
    
private:
    void pushAll(TreeNode* root) {
        while(root) {
            st.push(root);
            if(reverse) root = root->right;
            else root = root->left;
        }
    }
    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        
        BSTIterator *it1 = new BSTIterator(root, false);
        BSTIterator *it2 = new BSTIterator(root, true);
        
        int i = it1->next();
        int j = it2->next();
        
        while(i < j) {
            if(i + j == k) return true;
            if(i+j > k) j = it2->next();
            else i = it1->next();
        }
        
        return false;
    }
};