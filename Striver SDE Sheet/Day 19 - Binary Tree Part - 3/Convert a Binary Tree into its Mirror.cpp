class Solution {
private:

    void recur(Node* root) {
        if(!root) return;
        
        recur(root->left);
        recur(root->right);
        
        Node* tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        
        return;
    }

public:
// Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        recur(node);
    }
};