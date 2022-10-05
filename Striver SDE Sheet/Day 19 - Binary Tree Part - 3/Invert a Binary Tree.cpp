#include <bits/stdc++.h> 
#define Node TreeNode<int>

bool helper(Node* root, Node* leaf, stack<Node*>& st) {
    if(!root) return false;
    
    st.push(root);
    
    if(!root->left && !root->right) {
        if(root->data == leaf->data) return true;
        else {
            st.pop();
            return false;
        }
    }
    
    bool x = helper(root->left, leaf, st);
    bool y = helper(root->right, leaf, st);
    
    if(x || y) return true;
    
    st.pop();
    return false;
    
}

TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    if(!root) return root;
    
    stack<Node*> st;
    helper(root, leaf, st);
    
    Node* newRoot = st.top(); st.pop();
    Node* parent = newRoot;
    
    while(!st.empty()) {
        Node* curr = st.top(); st.pop();
        
        if(parent == curr->left) {
            parent->left = curr;
            curr->left = NULL;
        }
        else {
            curr->right = curr->left;
            curr->left = NULL;
            parent->left = curr;
        }
        
        parent = parent->left;
    }
    
    return newRoot;
}
